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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1)
		{
			TreeNode *r = new TreeNode(val);
			r->left = root;
			return r;
		}

		queue<TreeNode *> q;
		q.push(root);
		int d = 1;

		while (!q.empty())
		{
			int n = q.size();
			for (int i = 0; i < n; ++i)
			{
				TreeNode *f = q.front();
				q.pop();

				if (d == depth - 1)
				{
					TreeNode *l = new TreeNode(val);
					TreeNode *r = new TreeNode(val);

					l->left = f->left;
					r->right = f->right;

					f->left = l;
					f->right = r;

					continue;
				}

				if (f->left) q.push(f->left);
				if (f->right) q.push(f->right);
			}
			++d;
		}

		return root;
    }
};