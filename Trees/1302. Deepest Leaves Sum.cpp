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
    void f(TreeNode* root, map<int,int>&m,int level)
    {
        if(!root)
            return;
        m[level] += root->val;
        f(root->left,m,level+1);
        f(root->right,m,level+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        map<int,int>m;
        f(root,m,0);
        map<int,int> :: iterator itr;
        int ans = 0;
        for(itr = m.begin(); itr != m.end(); itr++)
            ans = itr->second;
        return ans;
    }
};