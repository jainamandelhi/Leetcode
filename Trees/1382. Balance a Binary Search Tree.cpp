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
int n;
void inorder(TreeNode *root)
{
    if( !root )
        return;
    inorder ( root -> left );
    arr.push_back( root -> val );
    inorder( root -> right );
}
TreeNode* convert(int i , int j)
{
    if(i > j)
        return NULL;
    int mid = i + ( j - i ) / 2;
    TreeNode *temp = new TreeNode(arr[mid]);
    temp -> left = convert(i , mid-1);
    temp -> right = convert(mid + 1 , j);
    return temp;
}
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        arr = vector <int> ();
        inorder( root );
        n = arr.size();
        int i = 0 , j = n-1 ;
        TreeNode *ans = convert(i , j);
        return ans;
    }
};