/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int at=-1,bt=-1;
void fun(TreeNode* root,int x,int y,int level)
{
    if(!root)
        return;
    if(root->left && root->right)
    {
        if(root->left->val==x && root->right->val==y)
            return;
        if(root->right->val==x && root->left->val==y)
            return;
    }
    if(root->val==x)
        at=level;
    if(root->val==y)
        bt=level;
    fun(root->left,x,y,level+1);
    fun(root->right,x,y,level+1);
}
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        at=-1,bt=-1;
        fun(root,x,y,0);
        if(at==-1 || bt==-1)
            return 0;
        if(at!=bt)
            return 0;
        return 1;
    }
};