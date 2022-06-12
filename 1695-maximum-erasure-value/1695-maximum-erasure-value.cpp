class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0, maxSum = 0;
        set<int> unique;
        
        for (int i = 0, j = 0; i < nums.size();)
        {
            if (unique.find(nums[i]) == unique.end())
            {
                sum += nums[i];
                unique.insert(nums[i]);
                ++i;
            }
            else
            {
                sum -= nums[j];
                unique.erase(nums[j]);
                ++j;
            }
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};