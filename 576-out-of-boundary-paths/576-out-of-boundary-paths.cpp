class Solution { 
    int mod = 1000000007;
    int dp[51][51][51];
    
    long long ans(int m, int n, int mv, int i, int j)
    {
        if (i < 0 || j < 0 || i >= m || j >= n)
            return 1;
        
        if (mv <= 0)
            return 0;
        
        if (dp[i][j][mv] != -1)
            return dp[i][j][mv];
        
        long long count = 0;
        
        count += ans(m, n, mv - 1, i + 1, j);
        count += ans(m, n, mv - 1, i - 1, j);
        count += ans(m, n, mv - 1, i, j + 1);
        count += ans(m, n, mv - 1, i, j - 1);

        return dp[i][j][mv] = count % mod;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return ans(m, n, maxMove, startRow, startColumn);
    }
};