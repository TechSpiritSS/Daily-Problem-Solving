class Solution {
    void dfs(int n, vector<vector<int>> &adj, vector<bool> &visit)
    {
        visit[n] = true;
        
        for (auto &i : adj[n])
            if (!visit[i])
                dfs(i, adj, visit);
    }
    
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        
        vector<vector<int>> adj(n);
        
        for (auto &i : connections)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        int c = -1;
        vector<bool> visit(n);
        
        for (int i = 0; i < n; ++i)
            if (!visit[i])
            {
                ++c;
                dfs(i, adj, visit);
            }
        
        return c;
    }
};