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
    int ans = 0;
    
    int depth(TreeNode *root)
    {
        if (!root)
            return 0;
    
        int l = depth(root -> left);
        int r = depth(root -> right);
        return 1 + max(l, r);
    }
    
    void solve(TreeNode *root,int max_depth,int i)
    {
        if (!root)
            return;
        
        if (i == max_depth - 1)
            ans += root -> val;
        
        solve(root -> left, max_depth, i + 1);
        solve(root -> right, max_depth, i + 1);
        
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int max_depth = depth(root);
        
        solve(root, max_depth, 0);
        
        return ans;
    }
};