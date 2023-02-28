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
    unordered_map<string, int> m;
    vector<TreeNode*> ans;
    
    string solve(TreeNode* r)
    {
        if (!r) return "";
        
        string left = solve(r -> left);
        string right = solve(r -> right);
        string s = left + "," + right + "," + to_string(r -> val);
        
        if (m[s] == 1) ans.push_back(r);
        ++m[s];
        return s;
    }
    
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) { 
        solve(root);
        return ans;
    }
};