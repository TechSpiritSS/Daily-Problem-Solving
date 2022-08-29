class Solution {
    void dfs(int i, int j, vector<vector<char>> &grid, int row, int col)
    {
         if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == '0') 
             return;
        
        grid[i][j] = '0'; 
        dfs(i - 1, j, grid, row, col);
        dfs(i + 1, j, grid, row, col); 
        dfs(i, j - 1, grid, row, col);
        dfs(i, j + 1, grid, row, col);
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int count = 0;
        for ( int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (grid[i][j] == '1')
                {
                    dfs(i, j, grid, row, col);
                    ++count;
                }
        return count;
    }
};