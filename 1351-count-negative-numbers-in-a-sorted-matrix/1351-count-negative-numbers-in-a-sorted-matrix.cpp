class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < n; ++i)
        {
            int s = 0;
            int e = m - 1;
        
            while (s <= e) 
            {
                int mid = s + (e - s) / 2;
                if (grid[i][mid] < 0)
                    e = mid - 1;
                else 
                    s = mid + 1;
            }
            
            if (s < m)
                count += m - s;
        }
        return count;
    }
};