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
    vector<int>v;
    void f(TreeNode* root)
    {
        if(!root)
            return;
        v.push_back(root -> val);
        f(root -> left);
        f(root -> right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        f(root1);
        f(root2);
        sort(v.begin(),v.end());
        return v;
    }
};