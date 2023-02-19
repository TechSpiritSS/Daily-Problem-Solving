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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        bool dir = true;
        while (!q.empty())
        {
            int s = q.size();
            vector<int> c(s);
            
            for (int i = 0; i < s; ++i)
            {
                TreeNode* tmp = q.front();
                q.pop();
                
                if (dir) c[i] = tmp -> val;
                else c[s - i - 1] = tmp -> val;
                
                if (tmp -> left) q.push(tmp -> left);
                if (tmp -> right) q.push(tmp -> right);
            }
            
            ans.push_back(c);
            dir = !dir;
        }
        return ans;
    }
};