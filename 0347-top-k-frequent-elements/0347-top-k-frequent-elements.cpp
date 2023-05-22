class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> f;
		for (auto &i : nums) ++f[i];

		priority_queue<pair<int, int>> q;
		for (auto &i : f) q.push({i.second, i.first});

		vector<int> ans;
		while (k--)
		{
			ans.push_back(q.top().second);
			q.pop();
		}

		return ans;
    }
};