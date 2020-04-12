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
    int f(TreeNode* root)
    {
        if(!root)
            return 0;
        return max(1+f(root->left),1+f(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        return max(f(root->left)+f(root->right),max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
};