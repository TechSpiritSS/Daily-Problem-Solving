class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int ans = INT_MAX;
        int min_diff = INT_MAX;
        
        for (int k = 0; k < nums.size(); ++k)
        {
            int i = k + 1;
            int j = nums.size() - 1;
            while (i < j)
            {
                int tmp = nums[i] + nums[j] + nums[k];
                int diff = abs(target - tmp);
                
                if (min_diff > diff)
                {
                    min_diff = diff;
                    ans = tmp;
                    if (ans == target) return ans;
                }
                
                if (tmp > target) --j;
                else ++i;
            }
        }
        
        return ans;
    }
};