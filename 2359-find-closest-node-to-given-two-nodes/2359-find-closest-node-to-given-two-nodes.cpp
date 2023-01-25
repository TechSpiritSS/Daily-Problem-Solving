class Solution {
    void dfs(vector<int> &e, int n, vector<int> &d)
    {
        int dist = 0;
        for (int i = n; i != -1 && d[i] == -1; i = e[i])
            d[i] = dist++;
    }
        
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int s = edges.size();
        vector<int> d1(s, -1), d2(s, -1);
        
        dfs(edges, node1, d1);
        dfs(edges, node2, d2);
        
        int min_d = INT_MAX;
        int ans = -1;
        
        for (int i = 0; i < s; ++i)
            if (min(d1[i], d2[i]) >= 0 && max(d1[i], d2[i]) < min_d)
            {
                ans = i;
                min_d = max( d1[i], d2[i] );
            }
        return ans;
    }
};