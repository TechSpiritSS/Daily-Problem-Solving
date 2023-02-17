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
    
    void bfs(TreeNode* r)
    {
        if (!r) return;
        v.push_back(r -> val);
        bfs(r -> left);
        bfs(r -> right);
    }
    
public:
    int minDiffInBST(TreeNode* root) { 
        int ans = INT_MAX;
        bfs(root);
        
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); ++i)
            ans = min(v[i] - v[i - 1], ans);
        return ans;
    }
};