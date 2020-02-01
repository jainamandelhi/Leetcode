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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(val==root->val)
            return root;
        if(val>root->val)
        {
            if(!root->right)
                return NULL;
            return searchBST(root->right,val);
        }
        else
        {
            if(!root->left)
                return NULL;
            return searchBST(root->left,val);
        }
    }
};