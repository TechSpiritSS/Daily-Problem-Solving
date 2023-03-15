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
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        
        while (!q.empty())
        {
            TreeNode* n = q.front();
            q.pop();
            
            if (n -> left)
            {
                if (flag) return false;
                q.push(n -> left);
            } 
            else flag = true;
            
            if (n -> right)
            {
                if (flag) return false;
                q.push(n -> right);
            }
            else flag = true;
        }
        return true;
    }
};