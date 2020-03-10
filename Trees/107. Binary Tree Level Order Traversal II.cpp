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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> >v;
        if(!root)
            return v;
        vector<int>temp;
        queue<pair<TreeNode*,int> >q;
        q.push(make_pair(root,0));
        int maxi=0;
        while(!q.empty())
        {
            TreeNode* t=q.front().first;
            int a=q.front().first->val;
            int l=q.front().second;
            q.pop();
            if(l>maxi)
            {
                v.push_back(temp);
                temp=vector<int>();
                maxi=l;
                temp.push_back(a);
            }
            else
                temp.push_back(a);
            if(t->left)
            {
                q.push(make_pair(t->left,l+1));
            }
            if(t->right)
            {
                q.push(make_pair(t->right,l+1));
            }
            if(q.empty())
                v.push_back(temp);
        }
        vector<vector<int> >ans;
        for(int i=v.size()-1;i>=0;i--)
            ans.push_back(v[i]);
        return ans;
    }
};