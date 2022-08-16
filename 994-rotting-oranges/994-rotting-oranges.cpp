class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int ans = 0, clean = 0;
        queue<pair<int, int>> rotten;

        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[i].size(); ++j)
                if (grid[i][j] == 2)
                    rotten.push({i, j});
                else if (grid[i][j] == 1)
                    ++clean;

        rotten.push({-1, -1});

        while (rotten.size())
        {
            auto [x, y] = rotten.front();
            rotten.pop();

            if (x == -1)
            {
                if (rotten.size())
                {
                    rotten.push({-1, -1});
                    ++ans;
                }
                continue;
            }

            int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size())
                    continue;

                if (grid[nx][ny] == 1)
                {
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                    --clean;
                }
            }
        }

        return clean ? -1 : ans;
    }
};