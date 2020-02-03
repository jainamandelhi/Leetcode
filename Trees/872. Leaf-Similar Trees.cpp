/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int>arr1,arr2;
void dfs1(TreeNode *root)
{
    if(!root)
        return;
    if(!root->left && !root->right)
        arr1.push_back(root->val);
    if(root->left)
        dfs1(root->left);
    if(root->right)
        dfs1(root->right);
}
void dfs2(TreeNode *root)
{
    if(!root)
        return;
    if(!root->left && !root->right)
        arr2.push_back(root->val);
    if(root->left)
        dfs2(root->left);
    if(root->right)
        dfs2(root->right);
}
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        arr1=vector<int>();
        arr2=vector<int>();
        dfs1(root1);
        dfs2(root2);
        return arr1==arr2;
    }
};