class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        int l = 1;
        ans.push_back(nums[0]);
        
        for (auto &i : nums)
            if (i > ans.back())
            {
                ans.push_back(i);
                ++l;
            }
            else
            {
                int idx = lower_bound(ans.begin(), ans.end(), i) - ans.begin();
                ans[idx] = i;
            }
        return l;
    }
};