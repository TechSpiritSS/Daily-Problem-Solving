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
    bool sol(TreeNode* r, TreeNode* min, TreeNode* max)
    {
        if (!r) return true;
        if (min && r -> val <= min -> val) return false;
        if (max && r -> val >= max -> val) return false;
        return sol(r -> left, min, r) && sol(r -> right, r, max);            
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return sol(root, NULL, NULL);
    }
};