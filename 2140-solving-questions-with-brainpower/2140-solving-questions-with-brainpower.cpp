class Solution {
    vector<long long> dp;
    
    long long dfs(vector<vector<int>> &q, int i)
    {
        if (i >= q.size()) return 0;
        if (dp[i] != 0) return dp[i];
        
        long long a = q[i][0];
        long long s = q[i][1];
        
        dp[i] = max(a + dfs(q, i + s + 1), dfs(q, i + 1));
        return dp[i];
    }
    
public:
    long long mostPoints(vector<vector<int>>& questions) {
        dp.resize(questions.size());
        return dfs(questions, 0);
    }
};