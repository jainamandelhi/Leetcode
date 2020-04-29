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
    int ans = INT_MIN;
    int f(TreeNode *root)
    {
        if(!root)
            return 0;
        int a = f(root->left);
        int b = f(root->right);
        ans = max(ans,root -> val+max(a,max(b,max(0,a+b))));
        root -> val += max(a,max(b,0));
        return root -> val;
    }
    int maxPathSum(TreeNode* root) {
        f(root);
        return ans;
    }
};