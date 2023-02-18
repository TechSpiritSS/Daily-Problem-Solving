class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;
        
        for (auto &i : nums)
        {
            if (sum < 0) sum = 0;
            sum += i;
            ans = max(ans, sum);
        }
        return ans;
    }
};