/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans = 0;
int f(TreeNode* root)
{
    if(!root)
        return 0;
    int b1=0,b2=0;
    b1 += f(root -> left);
    b2 += f(root -> right);
    if(!root->left && !root->right)
    {
        ans = max(ans,root->val);
        return root->val;
    }
    else if(root -> left && root -> right)
    {
        if(root->val > root->left->val && root->val < root->right->val && b1!=INT_MIN &&                    b2!=INT_MIN)
        {
            int c = b1 + b2 + root->val;
            ans = max(ans,c);
            return c;
        }
        else
        {
            return INT_MIN;
        }
    }
    else if(root -> left)
    {
        if(root->val > root->left->val && b1!=INT_MIN)
        {
            int c = b1 + root->val;
            ans = max(ans,c);
            return c;
        }
        else
        {
            return INT_MIN;
        }
    }
    else if(root -> right)
    {
        if(root->val < root->right->val && b2!=INT_MIN)
        {
            int c = b2 + root->val;
            ans = max(ans,c);
            return c;
        }
        else
        {
            return INT_MIN;
        }
    }
    return INT_MIN;
}
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        ans = 0;
        if(!root)
            return 0;
        f(root);
        return ans;
    }
};