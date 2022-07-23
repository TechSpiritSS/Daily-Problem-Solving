class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101);
        
        for (auto &i : nums)
            ++count[i];
        
        for (int i = 1; i < 101; ++i)
            count[i] += count[i - 1];
        
        vector<int> ans(nums.size());
        
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] > 0)
                ans[i] = count[nums[i] - 1];
        
        return ans;
    }
};