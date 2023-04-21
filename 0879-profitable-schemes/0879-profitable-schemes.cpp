class Solution {
    int MOD = 1e9 + 7;
    int dp[101][101][101];
    
    int solve(int i, int c, int p, int n, int minp, vector<int> &g, vector<int> &profits)
    {
        if (i == g.size()) return p >= minp;
        if (dp[i][c][p] != -1) return dp[i][c][p];
        
        int ans = solve(i + 1, c, p, n, minp, g, profits);
        if (c + g[i] <= n)
            ans += solve(i + 1, c + g[i], min(minp, p + profits[i]), n, minp, g, profits);
    
        return dp[i][c][p] = ans % MOD;   
    }    
    
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, n, minProfit, group, profit);
    }
};