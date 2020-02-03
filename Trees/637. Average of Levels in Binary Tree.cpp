/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void dfs(TreeNode *root,map<int,vector<int> >&m,int cnt)
{
    if(!root)
        return;
    dfs(root->left,m,cnt+1);
    m[cnt].push_back(root->val);
    dfs(root->right,m,cnt+1);
}
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        map<int,vector<int> >m;
        dfs(root,m,0);
        vector<double>v;
        for(int i=0;i<m.size();i++)
        {
            double a=0;
            for(int j=0;j<m[i].size();j++)
                a+=m[i][j];
            v.push_back(a/m[i].size());
        }
        return v;
    }
};