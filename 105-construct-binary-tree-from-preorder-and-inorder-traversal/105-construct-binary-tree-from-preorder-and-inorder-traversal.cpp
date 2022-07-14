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
    int pi = 0;
    map<int, int> in;
    TreeNode* tree(vector<int> &pre, int l, int r)
    {
        if (l > r)
            return NULL;
        
        int val = pre[pi++];
        TreeNode* root = new TreeNode(val);
        
        root -> left = tree(pre, l, in[val] - 1);
        root -> right = tree(pre, in[val] + 1, r);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i)
            in[inorder[i]] = i;
        
        return tree(preorder, 0, preorder.size() - 1);
    }
};