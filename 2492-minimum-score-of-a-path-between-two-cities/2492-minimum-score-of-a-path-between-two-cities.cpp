class Solution {
    int ans;
    
    void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<bool> &v)
    {
        v[node] = true;
        
        for (auto &i : adj[node])
        {
            ans = min(ans, i.second);
            if (!v[i.first]) dfs(i.first, adj, v);
        }
    }
    
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        
        for (auto &i : roads)
        {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        
        vector<bool> v(n + 1);
        
        ans = INT_MAX;
        dfs(1, adj, v);
        
        return ans;
    }
};