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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ip = inorder.size() - 1,
            pp = postorder.size() - 1;
        
        stack<TreeNode*> s;
        
        TreeNode *prev = NULL,
                 *root = new TreeNode(postorder[pp]);
        
        s.push(root);
        --pp;
        
        while (pp >= 0)
        {
            while (!s.empty() && s.top() -> val == inorder[ip])
            {
                prev = s.top();
                s.pop();
                --ip;
            }
            
            TreeNode* n = new TreeNode(postorder[pp]);
           
            if (prev) prev -> left = n;
            else if (!s.empty()) s.top() -> right = n;
            
            s.push(n);
            prev = NULL;
            --pp;
        }
        return root;
    }
};