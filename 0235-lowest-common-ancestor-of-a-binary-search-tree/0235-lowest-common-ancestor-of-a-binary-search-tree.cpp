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
    TreeNode *ans = NULL;
    
    bool solve(TreeNode *r, TreeNode *p, TreeNode *q)
    {
        if (!r) return false;
        
        bool left = solve(r -> left, p, q);
        bool right = solve(r -> right, p, q);
        bool mid = (r == p || r == q);
        
        if ((left && right) || (mid && left) || (mid && right))
            ans = r;
        
        return mid || right || left;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root, p, q);
        return ans;
    }
};