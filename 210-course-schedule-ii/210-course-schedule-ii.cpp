class Solution {
    vector<int> ans;
    vector<int> visit;
    unordered_map<int, vector<int>> graph;
    bool loop = false;

    void dfs(int i) {
        if (visit[i] == 1)
        {
            loop = true;
            return;
        }

        visit[i] = 1;

        for (auto &i : graph[i])
        {
            if (visit[i] != 2)
                dfs(i);
            if (loop)
                return;
        }

        ans.push_back(i);
        visit[i] = 2;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        visit = vector<int>(numCourses);

        for (auto &i : prerequisites)
            graph[i[0]].push_back(i[1]);

        for (int i = 0; i < numCourses && !loop; ++i)
            if (visit[i] != 2)
                dfs(i);

        return loop ? vector<int>() : ans;
    }
};