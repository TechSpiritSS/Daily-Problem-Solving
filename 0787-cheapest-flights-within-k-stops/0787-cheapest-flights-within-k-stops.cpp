class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        
        for (auto &i : flights)
            adj[i[0]].push_back({i[1], i[2]});
        
        vector<int> stops(n, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});
        
        while (!pq.empty())
        {
            auto tmp = pq.top();
            pq.pop();
            
            int d = tmp[0], n = tmp[1], steps = tmp[2];
            
            if (steps > stops[n] || steps > k + 1) continue;                        
            stops[n] = steps;
            if (n == dst) return d;
            
            for (auto & [ad, p] : adj[n])
                pq.push({d + p, ad, steps + 1});
        }
        return -1;
    }
};