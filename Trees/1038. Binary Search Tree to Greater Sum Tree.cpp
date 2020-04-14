/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    void f(TreeNode *root)
    {
        if(!root)
            return;
        f(root->right);
        sum += root->val;
        root->val = sum;
        f(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        f(root);
        return root;
    }
};