class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, diff = 0, m = nums.size() / 2;
        
        for (auto &i : nums)
            ans += abs(i - nums[m]);
               
        return ans;
    }
};