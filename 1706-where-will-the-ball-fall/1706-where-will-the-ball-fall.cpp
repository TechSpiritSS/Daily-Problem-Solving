class Solution {
    int solve(vector<vector<int>> &g, int i)
    {        
        for (auto &r : g)
        {
            if (i < 0 || i > r.size())
                return false;
            
            if (r[i] == 1)
            {
                if (i + 1 >= r.size() || r[i + 1] == -1)
                    return -1;
                else
                    ++i;
            }
            else if (r[i] == -1)
            {
                if (i == 0 || r[i - 1] == 1)
                    return -1;
                else
                    --i;
            }
        }
        return i;
    }
    
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        int s = grid[0].size();
        
        for (int i = 0; i < s; ++i)
            ans.push_back(solve(grid, i));
        
        return ans;
    }
};