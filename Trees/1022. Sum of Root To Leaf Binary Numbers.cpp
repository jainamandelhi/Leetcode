/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int convert(string s)
{
    int n=s.size();
    int m=0;
    int j=0;
    for(int i=n-1;i>=0;i--)
    {
        m=m+pow(2,j)*(s[i]-'0');
        j++;
    }
    return m;
}
int func(TreeNode* root, string s)
{
    int ans=0;
    s.push_back(root->val+'0');
    if(!root->left && !root->right)
    {
        return convert(s);
    }
    if(root->left)
        ans+=func(root->left,s);
    if(root->right)
        ans+=func(root->right,s);
    s.pop_back();
    return ans;
}
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if(!root)
            return 0;
        return func(root,"");  
    }
};