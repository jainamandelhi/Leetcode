/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int>arr;
void f1(TreeNode *root)
{
    if(!root)
        return;
    f1(root->left);
    root->val=arr[arr.size()-1];
    arr.pop_back();
    f1(root->right);
}
void f(TreeNode *root)
{
    if(!root)
        return;
    f(root->left);
    arr.push_back(root->val);
    f(root->right);
}
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        arr=vector<int>();
        if(!root)
            return root;
        f(root);
        int n=arr.size();
        for(int i=n-2;i>=0;i--)
        {
            arr[i]+=arr[i+1];
        }
        reverse(arr.begin(),arr.end());
        f1(root);
        return root;
    }
};