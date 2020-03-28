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
    int maxLevelSum(TreeNode* root) {
        vector<int>ans(100001);
        queue<pair<TreeNode*,int> >q;
        q.push(make_pair(root,1));
        while(!q.empty())
        {
            TreeNode* fi = q.front().first;
            int se = q.front().second;
            q.pop();
            ans[se] += fi->val;
            if(fi->left)
                q.push(make_pair(fi->left,se+1));
            if(fi->right)
                q.push(make_pair(fi->right,se+1));
        }
        int val = INT_MIN,index = 0;
        for(int i=1;i<=10002;i++)
        {
            if(ans[i] > val)
                index = i;
            val = max(val,ans[i]);
        }
        return index;
    }
};