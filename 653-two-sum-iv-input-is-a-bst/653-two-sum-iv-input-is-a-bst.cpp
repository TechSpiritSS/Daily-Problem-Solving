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
    set<int> s;

    public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        
        int y = k - root -> val;
        
        for (auto &i : s)
            if (i == y) return true;
        s.insert(root -> val);
        s.insert(y);
        
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};