class Solution {
    int area(vector<vector<int>> &grid, int r, int c)
    {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || !grid[r][c])
            return 0;
    
        grid[r][c] = 0;
        return 1 + area(grid, r + 1, c) + area(grid, r - 1, c) + area(grid, r, c + 1) + area(grid, r, c - 1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int r = 0; r < grid.size(); ++r)
            for (int c = 0; c < grid[0].size(); ++c)
                ans = max(ans, area(grid, r, c));
        
        return ans;
    }
};