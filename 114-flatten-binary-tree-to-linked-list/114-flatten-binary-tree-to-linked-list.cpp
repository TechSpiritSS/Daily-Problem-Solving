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
    TreeNode* end(TreeNode * r)
    {
        if (!r -> right)
            return r;
        return end(r -> right);
    }
    
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        
        TreeNode* right = NULL, *r_end = NULL;
        
        while (root)
        {
            if (root -> left)
            {
                r_end = end(root -> left);
                right = root -> right;
                root -> right = root -> left;
                root -> left = NULL;
                r_end -> right = right;
            }
            root = root -> right;
        }
    }
};