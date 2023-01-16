class Solution {
    bool overlap(vector<int> &c, vector<int> &i)
    {
        return min(c[1], i[1]) - max(c[0], i[0]) >= 0;
    }
    
    void solve(vector<vector<int>> &i, vector<int> &n)
    {
        int idx = upper_bound(i.begin(), i.end(), n) - i.begin();
        
        if (idx != i.size()) i.insert(i.begin() + idx, n);
        else i.push_back(n);
    }
    
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        solve(intervals, newInterval);
        
        for (int i = 0; i < intervals.size(); ++i)
        {
            vector<int> curr = {intervals[i][0], intervals[i][1]};
            while (i < intervals.size() && overlap(curr, intervals[i]))
            {
                curr = { min(curr[0], intervals[i][0]), max(curr[1], intervals[i][1]) };
                ++i;
            }
            ans.push_back(curr);
            --i;
        }
        return ans;
    }
};