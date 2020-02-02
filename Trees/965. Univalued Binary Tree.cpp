/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool dfs(TreeNode* root,int val)
{
    if(!root)
        return 1;
    if(root->val!=val)
        return 0;
    return 1 && dfs(root->left,val) && dfs(root->right,val);
}
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(!root)
            return false;
        return dfs(root,root->val);
    }
};