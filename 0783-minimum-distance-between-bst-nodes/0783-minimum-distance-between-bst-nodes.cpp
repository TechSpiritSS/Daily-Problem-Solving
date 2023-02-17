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
    int ans = INT_MAX;
    TreeNode* p = NULL;
    
    void inorder(TreeNode* r)
    {
        if (!r) return;
        inorder(r -> left);
        if (p) ans = min(ans, r -> val - p -> val);
        p = r;
        inorder(r -> right);
    }
    
public:
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return ans;
    }
};