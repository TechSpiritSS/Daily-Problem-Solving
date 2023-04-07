class Solution {
    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 || i >= grid.size() 
            || j < 0 || j >= grid[0].size()) return;
        
        if (!grid[i][j]) return;
        
        grid[i][j] = 0;
        
        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0,
            m = grid.size() - 1,
            n = grid[0].size() - 1;
        
        for (int i = 0; i <= m; ++i)
            for (int j = 0; j <= n; ++j)
                if (i == 0 || i == m || j == 0 || j == n)
                    dfs(i, j, grid);
        
        for (int i = 0; i <= m; ++i)
            for (int j = 0; j <= n; ++j)
                ans += grid[i][j];
        
        return ans;
    }
};