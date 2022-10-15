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
    int depth(TreeNode *r, int d) {
		if (!r) return d;
		return max(depth(r -> left, d + 1), depth(r -> right, d + 1));
	}

public:
	int maxDepth(TreeNode *root) {
		return depth(root, 0);
	}
};