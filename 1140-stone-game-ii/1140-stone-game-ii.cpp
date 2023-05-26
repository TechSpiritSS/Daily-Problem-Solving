class Solution {
    int solve(vector<int> &p, vector<vector<int>> &dp, const vector<int> &s, int i, int m)
    {
        if (i == p.size()) return 0;
        if (i + 2 * m >= p.size()) return s[i];
        if (dp[i][m]) return dp[i][m];
        int res = 0;
        
        for (int x = 1; x <= 2 * m; ++x)
            res = max(res, s[i] - solve(p, dp, s, i + x, max(m, x)));
        
        dp[i][m] = res;
        return res;                            
    }
    
public:
    int stoneGameII(vector<int>& piles) {
        if (piles.empty()) return 0;
        
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size()));
        vector<int> s(piles.size());
        
        s[s.size() - 1] = piles[piles.size() - 1];
        
        for (int i = piles.size() - 2; i >= 0; --i)
            s[i] = piles[i] + s[i + 1];
        
        return solve(piles, dp, s, 0, 1);
    }
};
