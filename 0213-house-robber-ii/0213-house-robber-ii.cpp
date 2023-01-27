class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return nums[0];
        
        int c1 = nums[0], c2 = nums[1];
        int p1 = 0, p2 = 0;
        
        for (int i = 2; i < n; ++i)
        {
            int t1 = max(c1, p1 + nums[i - 1]);
            int t2 = max(c2, p2 + nums[i]);
            p1 = c1, p2 = c2;
            c1 = t1, c2 = t2;
        }
        
        return max(c1, c2);
    }
};