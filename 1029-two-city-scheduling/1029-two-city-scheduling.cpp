class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans = 0;
        
        vector<int> diff;
        
        for (vector<int> &i : costs)
        {
            ans += i[0];
            diff.push_back(i[1] - i[0]);
        }
        
        sort(diff.begin(), diff.end());
        
        int n = costs.size() / 2;
        
        for (int i = 0; i < n; ++i)
            ans += diff[i];
        
        return ans;
    }
};