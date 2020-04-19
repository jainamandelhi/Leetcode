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
    void f(TreeNode *root, int val)
    {
        if(root -> val < val){
            if(root -> right)
                f(root -> right,val);
            else
            {
                TreeNode *temp = new TreeNode(val);
                root -> right = temp;
                return;
            }
        }
        else{
            if(root -> left)
                f(root -> left,val);
            else
            {
                TreeNode *temp = new TreeNode(val);
                root -> left = temp;
                return;
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return NULL;
        f(root,val);
        return root;
    }
};