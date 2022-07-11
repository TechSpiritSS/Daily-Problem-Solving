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
    vector<int> ans;
    void rightVal(TreeNode* r, int h)
    {
        if (!r)
            return;
        
        if (ans.size() == h)
            ans.push_back(r -> val);
        
        rightVal(r -> right, h + 1);
        rightVal(r -> left, h + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {   
        rightVal(root, 0);
        return ans;
    }
};