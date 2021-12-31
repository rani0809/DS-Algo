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
    typedef tuple<TreeNode*, int, int> tup;


    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) return 0;

        stack <tup> s;
        int max_val = root->val, min_val = root->val, max_diff = 0;
        s.push(make_tuple(root, root->val, root->val));
        while(!s.empty()){
            tup cur_tup = s.top();
            s.pop();

            auto node = get<0>(cur_tup);
            int cur_max = get<1>(cur_tup), cur_min = get<2>(cur_tup);
            if(node->right){
                s.push(make_tuple(node->right, max(node->right->val, cur_max), min(node->right->val, cur_min)));
            }

            if(node->left){
                s.push(make_tuple(node->left, max(node->left->val, cur_max), min(node->left->val, cur_min)));
            }

            if(node->left==nullptr && node->right== nullptr){
                if (cur_max - cur_min > max_diff) max_diff = cur_max - cur_min;
            }

        }   

        return max_diff;
    }
    
};
