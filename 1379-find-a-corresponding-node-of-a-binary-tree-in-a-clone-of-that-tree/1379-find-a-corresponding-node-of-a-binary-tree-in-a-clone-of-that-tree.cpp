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
    TreeNode* ans;
    void inorder(TreeNode *o, TreeNode* c, TreeNode* target)
    {
        if (!o)
            return;
        
        inorder(o -> left, c -> left, target);
        
        if (o == target)
            ans = c;
        
        inorder(o -> right, c ->right, target);
            
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        inorder(original, cloned, target);
            return ans;
    }
};