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
 public:
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> v;
    if(!root) return v;
    queue<TreeNode*> q;
    q.push(root);
    int f =0;
    while(!q.empty())
    {
        int k= q.size();
        vector<int> tmp;
        while(k--)
        {
            TreeNode * tree = q.front();
            q.pop();
            if(tree->left) q.push(tree->left);
            if(tree->right) q.push(tree->right);
            tmp.push_back(tree->val);
        }
        if(f)
            {reverse(tmp.begin(), tmp.end()); f =0;}
        else
            f=1;
        v.push_back(tmp);
    }
    return v;
}
};