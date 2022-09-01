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
    int count;
    void dfs(TreeNode *r, int last) {
        if (!r)
            return;

        if (r->val >= last)
        {
            ++count;
            last = r->val;
        }

        dfs(r->left, last);
        dfs(r->right, last);
    }

public:
    int goodNodes(TreeNode *root) {
        count = 0;
        dfs(root, INT_MIN);
        return count;
    }
};