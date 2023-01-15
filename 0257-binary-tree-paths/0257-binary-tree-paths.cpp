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
    vector<string> ans;

    void dfs(TreeNode* r, string s)
    {
        if (!r) return;
        if (!r -> left && !r -> right)
        {
            s += to_string(r -> val);        
            ans.push_back(s);
            return;
        }        
        s += to_string(r -> val) + "->";
        dfs(r -> left, s);
        dfs(r -> right, s);
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = "";
        dfs(root, s);
        return ans;
    }
};