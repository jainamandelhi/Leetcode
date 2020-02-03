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
void dfs(TreeNode* root,int L,int R)
{
    if(!root)
        return;
    if(root->val>=L && root->val<=R)
        arr.push_back(root->val);
    dfs(root->left,L,R);
    dfs(root->right,L,R);
}
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root)
            return NULL;
        dfs(root,L,R);
        TreeNode *temp=new TreeNode(arr[0]);
        for(int i=1;i<arr.size();i++)
        {
            TreeNode* temp1=temp;
            while(1)
            {
                if(temp1->val<arr[i])
                {
                    if(temp1->right)
                    {
                        temp1=temp1->right;
                    }
                    else
                    {
                        TreeNode* p=new TreeNode(arr[i]);
                        temp1->right=p;
                        break;
                    }
                }
                else
                {
                    if(temp1->left)
                    {
                        temp1=temp1->left;
                    }
                    else
                    {
                        TreeNode* p=new TreeNode(arr[i]);
                        temp1->left=p;
                        break;
                    }
                }
            }
        }
        arr=vector<int>();
        return temp;
    }
};