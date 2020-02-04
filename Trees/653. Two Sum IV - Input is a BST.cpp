/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool f1(TreeNode *root,int p,TreeNode *root1)
{
    if(!root)
        return 0;
    if(root->val==p && root!=root1)
        return 1;
    bool b1=0,b2=0;
    if(root->val<p)
        b1=f1(root->right,p,root1);
    else
        b2=f1(root->left,p,root1);
    return b1 || b2;
}
bool f(TreeNode* root1, TreeNode* root2,int k)
{
    if(!root2)
        return 0;
    return f1(root1,k-root2->val,root2) || f(root1,root2->left,k) || f(root1,root2->right,k); 
}
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return 0;
        return f(root,root,k);
    }
};