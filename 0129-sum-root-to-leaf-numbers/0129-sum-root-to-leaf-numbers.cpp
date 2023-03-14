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
    int solve(TreeNode* r, int ans)
    {
        if (!r) return 0;
        ans *= 10;
        ans += r -> val;
        
        if (!r -> left && !r -> right) return ans;
        return solve(r -> left, ans) + solve(r -> right, ans);
    }
    
public:
    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};