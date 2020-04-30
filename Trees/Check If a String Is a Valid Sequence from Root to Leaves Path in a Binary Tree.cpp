/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int n;
    bool f(TreeNode *root, vector<int>&arr, int i)
    {
        if(i == n || !root)
            return false;
        if(i == n-1 && root -> val == arr[i] && !root -> left && !root -> right)
            return true;
        if(root -> val == arr[i] && (f(root -> left, arr, i+1) || (f(root -> right, arr, i+1))))
            return true;
        return false;
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        n = arr.size();
        if(!root && !n)
            return true;
        if(!root || !n)
            return false;
        return f(root,arr,0);
    }
};