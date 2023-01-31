class Solution {
    vector<vector<int>> dp;
    
    int solve(vector<pair<int, int>> &v, int p, int i)
    {
        if (i == v.size()) return 0;
        if (dp[p + 1][i] != -1) return dp[p + 1][i];
        if (p == -1 || v[i].second >= v[p].second)
            return dp[p + 1][i] = max(solve(v, p, i + 1), 
                                      v[i].second + solve(v, i, i + 1));
        return dp[p + 1][i] = solve(v, p, i + 1);
    }
    
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> v;
        dp = vector<vector<int>> (ages.size(), vector<int>(ages.size(), -1));
        
        for (int i = 0; i < ages.size(); ++i)
            v.push_back({ages[i], scores[i]});
        
        sort(v.begin(), v.end());
        return solve(v, -1, 0);
    }
};