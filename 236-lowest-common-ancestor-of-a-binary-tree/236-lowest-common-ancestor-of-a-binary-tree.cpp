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
    TreeNode* ans = NULL;
    
    bool sol(TreeNode* curr, TreeNode* p, TreeNode* q)
    {
        if (!curr) return false;
        
        bool left = sol(curr -> left, p, q);
        bool right = sol(curr -> right, p, q);
        
        bool mid = (curr == p || curr == q);
        
        if ((mid && left) || (mid && right) || (left && right))
            ans = curr;
        
        return mid || left || right;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        sol(root, p, q);
        return ans;
    }
};