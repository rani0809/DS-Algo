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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        
        return checkSymmetric(root->left, root->right);
    }
    //check the two nodes in symmetric position
    bool checkSymmetric(TreeNode *leftSymmetricNode, TreeNode *rightSymmetricNode)
    {
        if (leftSymmetricNode == NULL && rightSymmetricNode == NULL)
            return true;
        if (leftSymmetricNode == NULL || rightSymmetricNode == NULL)
            return false;
        if (leftSymmetricNode->val == rightSymmetricNode->val)
            return checkSymmetric(leftSymmetricNode->left, rightSymmetricNode->right) && checkSymmetric(leftSymmetricNode->right, rightSymmetricNode->left);
        return false;
    }
};