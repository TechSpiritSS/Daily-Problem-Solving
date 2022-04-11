class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> res;
        res = grid;
        int n = grid.size(), m = grid[0].size();
        while (k--)
        {
            for (int i = 0; i < n; ++i)
                for (int j = 1; j < m; ++j)
                    res[i][j] = grid[i][j - 1];
            
            for (int i = 0; i < n-1; ++i)
                res[i + 1][0] = grid[i][m - 1];
            
            res[0][0] = grid[n - 1][m - 1]; 
            grid = res; 
        }
        return res;
    }
};