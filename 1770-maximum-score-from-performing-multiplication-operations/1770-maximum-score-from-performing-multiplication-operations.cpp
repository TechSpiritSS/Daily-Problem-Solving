class Solution {
    vector<vector<int>> dp;

	int solve(vector<int> &nums, vector<int> &mult, int op, int num)
	{
		if (op == mult.size()) return 0;
		if (dp[op][num] != INT_MIN) return dp[op][num];

		int l = nums[num] * mult[op] + solve(nums, mult, op + 1, num + 1);
		int r = nums[(nums.size() - 1) - (op - num)] * mult[op] + solve(nums, mult, op + 1, num);

		return dp[op][num] = max(l, r);
	}

public:
	int maximumScore(vector<int> &nums, vector<int> &multipliers)
	{
        int n = nums.size();
        int m = multipliers.size();
        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));

		return solve(nums, multipliers, 0, 0);
	}
};