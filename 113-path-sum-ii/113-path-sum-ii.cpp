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
    vector<vector<int>> ans;

	void solve(TreeNode *r, int target, vector<int> &v)
	{
		if (!r) return;
		v.push_back(r->val);
		target -= r->val;

		if (!r->left && !r->right) {
			if (target == 0) ans.push_back(v);
		} else {
			solve(r->left, target, v);
			solve(r->right, target, v);
		}
		v.pop_back();
	}

public:
	vector<vector<int>> pathSum(TreeNode *root, int targetSum)
	{
		vector<int> v;
		solve(root, targetSum, v);
		return ans;
	}};