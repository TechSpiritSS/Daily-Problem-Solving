class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, bool>>> adj(n);
        
        for (auto &i : redEdges) adj[i[0]].push_back({i[1], 0});
        for (auto &i : blueEdges) adj[i[0]].push_back({i[1], 1});
    
        vector<int> ans(n, -1);
        vector<vector<bool>> v(n, vector<bool> (2));
        queue<vector<int>> q;
        
        q.push({0, 0, -1});
        v[0][1] = v[0][0] = true;
        ans[0] = 0;
        
        while (!q.empty())
        {
            auto e = q.front();
            q.pop();
            int node = e[0], s = e[1], pclr =e[2];
            
            for (auto &[nxt, clr] : adj[node])
                if (!v[nxt][clr] && clr != pclr)
                {
                    v[nxt][clr] = true;
                    q.push({nxt, s + 1, clr});
                    if (ans[nxt] == -1)
                        ans[nxt] = s + 1;
                }
        }
        return ans;
    }
};