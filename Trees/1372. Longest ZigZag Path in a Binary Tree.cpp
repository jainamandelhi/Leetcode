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
    void dfs(TreeNode *root,int dir,int cnt)
    {
        if(!root)
            return;
        if(root->left && dir==0)
        {
            dfs(root->left,1,cnt+1);
            dfs(root->left,0,0);
        }
        if(root->right && dir==1)
        {
            dfs(root->right,0,cnt+1);
            dfs(root->right,1,0);
        }
        ans = max(ans,cnt);
    }
    int longestZigZag(TreeNode* root) {
        dfs(root,0,0);
        dfs(root,1,0);
        return ans;
    }
};