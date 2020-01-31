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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum=0;
        if(root && root->val>=L && root->val<=R)
        {
            sum+=root->val;
            sum+=rangeSumBST(root->right,L,R);
            sum+=rangeSumBST(root->left,L,R);
        }
        else if(root && root->val<L)
        {
            sum+=rangeSumBST(root->right,L,R);
        }
        else if(root && root->val>R)
        {
            sum+=rangeSumBST(root->left,L,R);
        }
        return sum;
    }
};