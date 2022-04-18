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
    vector<int> v;
    void inorder(TreeNode* r)
    {
        if (!r)
            return;
        inorder(r -> left);
        v.push_back(r -> val);
        inorder(r -> right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        
        return v[k - 1];
    }
};