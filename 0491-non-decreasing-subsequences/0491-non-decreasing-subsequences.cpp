class Solution {
    set<vector<int>> ans;
    
    void solve(int i, vector<int> &nums, vector<int> &tmp)
    {
        if (nums.size() == i)
        {
            if (tmp.size() > 1) ans.insert(tmp);
            return;
        }
        
        int curr = nums[i];
        int prev = tmp.size() == 0 ? INT_MIN : tmp[tmp.size() - 1];
        
        if (curr >= prev)
        {
            tmp.push_back(curr);
            solve(i + 1, nums, tmp);
            
            tmp.pop_back();
            solve(i + 1, nums, tmp);
        }
        else solve(i + 1, nums, tmp);
    }
    
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> tmp;
        solve(0, nums, tmp);
        return vector(ans.begin(), ans.end());
    }
};