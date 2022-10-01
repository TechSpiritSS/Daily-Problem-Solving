class Solution {
    int dp[101];

	int solve(string s, int idx) {
		if (idx == s.size()) return 1;
		if (s[idx] == '0') return 0;
		if (dp[idx] != -1) return dp[idx];

		int first = solve(s, idx + 1);
		int second = 0;

		if (idx + 1 != s.size()) {
			int n = stoi(s.substr(idx, 2));
			if (n >= 1 && n <= 26) second = solve(s, idx + 2);
		}
		return dp[idx] = first + second;
	}

public:
	int numDecodings(string s) {
		memset(dp, -1, sizeof(dp));
		return solve(s, 0);
	}
};