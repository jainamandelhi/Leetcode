/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int f(TreeNode* root,int data)
{
    if(!root)
        return 0;
    if(root->val!=data)
        return 0;
    if(!root->left && !root->right)
        return 1;
    int a=0,b=0;
    a=f(root->left,data);
    b=f(root->right,data);
    return 1+max(a,b);
}
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root)
            return 0;
        return max(f(root->left,root->val)+f(root->right,root->val),max(longestUnivaluePath(root->left),longestUnivaluePath(root->right)));
    }
};