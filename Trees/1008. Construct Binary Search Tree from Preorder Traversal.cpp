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
    int i = 0;
    TreeNode *f(vector<int>&preorder,int parent)
    {
        if(i == preorder.size() || preorder[i] > parent)
            return NULL;
        TreeNode *root = new TreeNode(preorder[i++]);
        root -> left = f(preorder,root -> val);
        root -> right = f(preorder,parent);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return f(preorder,INT_MAX);
    }
};