class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        x = accumulate(nums.begin(), nums.end(), 0) - x;
        
        if (x < 0)
            return -1;
        
        if (x == 0)
            return nums.size();
        
        int ans = -1;
        
        for (int i = 0, j = 0, sum = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            for (j; sum > x; ++j)
                sum -= nums[j];
            if (sum == x)
                ans = max(ans, i - j + 1);
        }
        
        if (ans == -1)
            return ans;
        return nums.size() - ans;
    }
};
