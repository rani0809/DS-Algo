/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
        unordered_map<int, int> inm; // inorder map [inorder[i], i]

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size(), i = 0;
        for(auto val: inorder) inm[val] = i++; // build inm for dfs 
        
        return dfs(inorder, 0, n - 1, postorder, 0, n - 1);
    }
    
    TreeNode* dfs(vector<int>& inorder, int ileft, int iright, vector<int>& postorder, int pleft, int pright) {
        if(ileft > iright) return nullptr;
        
        int val = postorder[pright]; // root value
        TreeNode *root = new TreeNode(val);
        if(ileft == iright) return root;
        
        int iroot = inm[val];
        int nleft = iroot - ileft; // length of left subtree
        root->right = dfs(inorder, iroot + 1, iright, postorder, pleft + nleft, pright - 1);
        root->left = dfs(inorder, ileft, iroot - 1, postorder, pleft, pleft + nleft - 1);
        
        return root;
    }
};