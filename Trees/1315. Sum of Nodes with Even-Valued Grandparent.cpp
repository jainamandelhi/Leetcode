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
    void dfs(TreeNode *root)
    {
        if(!root)
            return;
        if(root->val%2 == 0 && root->left && root->left->left)
            sum += root->left->left->val;
        if(root->val%2 == 0 && root->left && root->left->right)
            sum += root->left->right->val;
        if(root->val%2 == 0 && root->right && root->right->left)
            sum += root->right->left->val;
        if(root->val%2 == 0 && root->right && root->right->right)
            sum += root->right->right->val;
        dfs(root->left);
        dfs(root->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
        if(!root)
            return 0;
       dfs(root); 
        return sum;
    }
};