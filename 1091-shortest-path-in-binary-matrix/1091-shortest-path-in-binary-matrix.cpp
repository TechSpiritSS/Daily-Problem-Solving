class Solution {
    int dir_x[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
    int dir_y[8] = {0, 0, -1, 1, 1, 1, -1, -1};
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = 1;
        
        if (grid[0][0]) return -1;
        
        if (grid.size() == 1) return ans;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        while (!q.empty())
        {
            int s = q.size();
            ++ans;
            
            for (int i = 0; i < s; ++i)
            {
                pair<int, int> p = q.front();
                q.pop();
                
                for (int a = 0; a < 8; ++a)
                {
                    int cx = p.first + dir_x[a];
                    int cy = p.second + dir_y[a];
                    
                    if (cx >= 0 && cx < grid.size() && cy < grid.size() && grid[cx][cy] == 0)
                    {
                        q.push({cx, cy});
                        grid[cx][cy] = 1;
                        if (cx == grid.size() - 1 && cy == grid.size() - 1)
                            return ans;
                    }
                }
            }
        }
        return -1;
    }
};