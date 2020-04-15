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
    int ans = 0;
    void trav(TreeNode *root)
    {
        if(!root)
            return;
        trav(root -> left);
        trav(root -> right);
        int a = 0, b = 0;
        if(root -> left)
            a = root -> left -> val;
        if(root -> right)
            b = root -> right -> val;
        root -> val = root->val + a + b - 1;
        ans += abs(abs(a)+abs(b));
    }
    int distributeCoins(TreeNode* root) {
        trav(root);
        return ans;
    }
};