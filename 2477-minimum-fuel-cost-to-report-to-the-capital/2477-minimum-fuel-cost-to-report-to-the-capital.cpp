class Solution {
    long long fuel;
    vector<vector<int>> adj;
    int seat;
    
    long long dfs(int n, int p)
    {
        int c = 1;
        for (auto &i : adj[n])
            if (i != p)
                c += dfs(i, n);
        
        if (n) fuel += ceil(c / (seat * 1.0));
        return c;
    }
    
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        adj.resize(roads.size() + 1);
        seat = seats;
        
        for (auto &i : roads)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        dfs(0, -1);
        return fuel;
    }
};