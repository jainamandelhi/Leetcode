/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* temp,*temp1;
void f(int a,TreeNode* temp1)
{
    TreeNode *p=new TreeNode(a);
    if(temp1==NULL)
    {
        temp1=p;
        temp=temp1;
        return;
    }
    if(a<=temp1->val){
        if(temp1->left==NULL)
        {
            temp1->left=p;
            return;
        }
        f(a,temp1->left);
    }
    else{
        if(temp1->right==NULL)
        {
            temp1->right=p;
            return;
        }
        f(a,temp1->right);
    }
}
void func(vector<int>&nums,int i,int j)
{
    if(j<i)
        return;
    int mid=i+(j-i)/2;
    f(nums[mid],temp1);
    temp1=temp;
    func(nums,i,mid-1);
    func(nums,mid+1,j);
}
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        temp1=NULL;
        temp=NULL;
        func(nums,0,nums.size()-1);
        return temp;
    }
};