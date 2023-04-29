class Solution {
    vector<vector<int>> ans;
    vector<int> v;
        
    void solve(int i, int t, vector<int> &c)
    {
        if (t == 0) 
        {
            ans.push_back(v);
            return;
        }
        
        for (int j = i; j < c.size(); ++j)
        {
            if (j > i && c[j] == c[j - 1]) continue;
            if (c[j] > t) continue;
            v.push_back(c[j]);
            solve(j + 1, t - c[j], c);
            v.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(0, target, candidates);
        return ans;
    }
};