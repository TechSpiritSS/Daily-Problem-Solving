class Solution {
    int m, n;
    void dfs(vector<vector<int>> &heights, int i, int j, set<pair<int, int>> &st, int ph) {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;
        if (st.find({i, j}) != st.end())
            return;
        if (heights[i][j] < ph)
            return;

        st.insert({i, j});

        dfs(heights, i - 1, j, st, heights[i][j]);
        dfs(heights, i + 1, j, st, heights[i][j]);
        dfs(heights, i, j - 1, st, heights[i][j]);
        dfs(heights, i, j + 1, st, heights[i][j]);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        set<pair<int, int>> atlantic;
        set<pair<int, int>> pacific;
        m = heights.size();
        n = heights[0].size();

        for (int i = 0; i < m; ++i)
        {
            dfs(heights, i, n - 1, atlantic, heights[i][n - 1]);
            dfs(heights, i, 0, pacific, heights[i][0]);
        }

        for (int i = 0; i < n; ++i)
        {
            dfs(heights, m - 1, i, atlantic, heights[m - 1][i]);
            dfs(heights, 0, i, pacific, heights[0][i]);
        }

        vector<vector<int>> res;

        for (auto it : atlantic)
            if (pacific.find(it) != pacific.end())
                res.push_back({it.first, it.second});

        return res;
    }
};