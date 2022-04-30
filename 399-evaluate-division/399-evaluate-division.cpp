class Solution {
    unordered_map<string, vector<pair<string, double>>> adj;
    unordered_map<string, bool> visited;
    double query;
    
   bool dfs(string s, string e, double prd){
        if (s == e && adj.find(s) != adj.end()) 
        {
            query = prd;
            return true;    
        }
        
        bool tempAns = false;
        visited[s] = true;
        
        for (int i = 0; i < adj[s].size(); ++i)
            if (!visited[adj[s][i].first])
            {
                tempAns = dfs(adj[s][i].first, e, prd * adj[s][i].second);
                if (tempAns)
                    break;
            }
        
        visited[s] = false;
        return tempAns;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size(), m = queries.size();
        vector<double> ans(m);
        
        for (int i = 0; i < n ; ++i)
        {
            adj[equations[i][0]].push_back( {equations[i][1], values[i]} );
            adj[equations[i][1]].push_back( {equations[i][0], 1 / values[i]} );
            visited[equations[i][0]] = false;
            visited[equations[i][1]] = false;
        }
        
        for (int i = 0; i < m; ++i)
        {
            query = 1;
            if (dfs(queries[i][0], queries[i][1], 1))
                ans[i] = query;
            else 
                ans[i] = -1;
        }
        
        return ans;
    }
};