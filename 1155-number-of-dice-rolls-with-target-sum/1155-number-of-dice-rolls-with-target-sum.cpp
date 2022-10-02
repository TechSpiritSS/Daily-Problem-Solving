class Solution {
    int MOD = 1e9 + 7;
	vector<vector<int>> dp;

	int solve(int n, int k, int target, int dice)
	{
		if (dice == n) return target == 0;
		if (dp[dice][target] != -1) return dp[dice][target];
		
        long ans = 0;
		for (int i = 1; i <= k; ++i)
			if (target - i >= 0) ans += (solve(n, k, target - i, dice + 1) % MOD);
            else break;
        
		return dp[dice][target] = ans % MOD;
	}

public:
	int numRollsToTarget(int n, int k, int target)
	{
		dp.resize(n + 1, vector<int>(target + 1, -1));
		return solve(n, k, target, 0);
	}
};