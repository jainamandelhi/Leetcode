/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    set<int>s;
    void f(TreeNode *root, int val)
    {
        if(!root)
            return;
        root -> val = val;
        s.insert(val);
        f(root -> left, 2*val + 1);
        f(root -> right, 2*val + 2);
    }
    FindElements(TreeNode* root) {
        if(root)
            f(root,0);
    }
    
    bool find(int target) {
        if(s.find(target) != s.end())
            return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */