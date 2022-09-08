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
    vector<int> ans;

    void inorder(TreeNode *r) {
        if (!r) return;

        inorder(r->left);
        ans.push_back(r->val);
        inorder(r->right);
    }

public:
    vector<int> inorderTraversal(TreeNode *root) {
        inorder(root);
        return ans;
    }
};