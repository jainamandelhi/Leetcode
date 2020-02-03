/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode *temp=new TreeNode(-1);
TreeNode* temp1=temp;
void dfs(TreeNode* root)
{
    if(!root)
        return;
    dfs(root->left);
    cout<<root->val<<endl;
    TreeNode* p = new TreeNode(root->val);
    temp->right=p;
    temp=temp->right;
    dfs(root->right);
}
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        temp=new TreeNode(-1);
        temp1=temp;
        dfs(root);
        return temp1->right;
    }
};