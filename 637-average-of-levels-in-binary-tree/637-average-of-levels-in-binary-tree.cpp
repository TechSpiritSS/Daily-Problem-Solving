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
	vector<double> averageOfLevels(TreeNode *root) {
		vector<double> ans;
		queue<TreeNode *> q;
		q.push(root);

		while (!q.empty())
		{
			int n = q.size();
			double sum = 0;
			for (int i = 0; i < n; ++i)
			{
				TreeNode *r = q.front();
				q.pop();
				sum += r->val;
				if (r->left)
					q.push(r->left);
				if (r->right)
					q.push(r->right);
			}
			ans.push_back((sum * 1.0) / n);
		}
		return ans;
	}
};