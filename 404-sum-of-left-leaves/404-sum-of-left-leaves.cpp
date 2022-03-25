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
    int ans = 0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
            return 0;
        
        if (root -> left && !root -> left -> left && !root -> left -> right)
            ans += root -> left -> val;
        
        sumOfLeftLeaves(root -> left);
        sumOfLeftLeaves(root -> right);      
        return ans;
    }
};