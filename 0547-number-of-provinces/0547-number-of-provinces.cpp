class Solution {
    void dfs(int node, vector<vector<int>>& c, vector<bool>& v) 
    {
        v[node] = true;
        
        for (int i = 0; i < c.size(); ++i) 
            if (c[node][i] && !v[i]) 
                dfs(i, c, v);
            
    }

    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        
        vector<bool> v(n);

        for (int i = 0; i < n; ++i)
            if (!v[i]) 
            {
                ++ans;
                dfs(i, isConnected, v);
            }

        return ans;
    }
};