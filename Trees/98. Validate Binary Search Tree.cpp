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
    int f1(TreeNode *root)
    {
        if(!root)
            return INT_MAX;
        return min(root->val,min(f1(root->left),f1(root->right)));
    }
    int f2(TreeNode *root)
    {
        if(!root)
            return INT_MIN;
        return max(root->val,max(f2(root->left),f2(root->right)));
    }
    bool isValidBST(TreeNode* root) {
       int a,b;
        if(!root)
            return true;
        bool b1 = true,b2 = true;
        if(root->right)
        {
            a = f1(root->right);
            if(root->val >= a)
                b1 = false;
       }
        if(root->left)
        {
            b = f2(root->left);
            if(root->val <= b)
                b2 = false;
        }
        return isValidBST(root->left) && isValidBST(root->right) && b1 && b2;
    }
};