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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode* > q;
        
        if (!root)
            return ans;
        
        q.push(root);
        
        while (!q.empty())
        {
            vector<int> x;
            int s = q.size();
            
            for (int i = 0; i < s; ++i)
            {
                TreeNode* r = q.front();
                q.pop();
                
                if (r -> left)
                    q.push(r -> left);
                if (r -> right)
                    q.push(r -> right);
                
                x.push_back(r -> val);
            }   
            ans.push_back(x);
        }
        return ans;
    }
};