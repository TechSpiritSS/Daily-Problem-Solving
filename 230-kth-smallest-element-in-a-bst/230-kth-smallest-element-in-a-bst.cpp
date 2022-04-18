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
    void inorder(TreeNode* r, int &k, int &a)
    {
        if (!r)
            return;
        inorder(r -> left, k, a);
        if (--k == 0)
        {
            a = r -> val;
            return;    
        }
        inorder(r -> right, k, a);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int a;
        inorder(root, k, a);
        return a;
    }
};