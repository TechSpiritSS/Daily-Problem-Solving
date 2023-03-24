class Solution {
    int ans = 0;
    
    void dfs(int n, int p, vector<vector<pair<int, int>>> &adj)
    {
        for (auto &[c, s] : adj[n])
            if (c != p)
            {
                ans += s;
                dfs(c, n, adj);
            }
    }
    
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        
        for (auto &i : connections)
        {
            adj[i[0]].push_back({i[1], 1});
            adj[i[1]].push_back({i[0], 0});
        }
        
        dfs(0, -1, adj);
        return ans;
    }
};