class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, s1 = 0, s2 = 0, maxs = INT_MIN, mins = INT_MAX;
        for (auto &i : nums)
        {
            total += i;
            s1 += i;
            s2 += i;
            maxs = max(maxs, s1);
            mins = min(mins, s2);
            if (s1 < 0) s1 = 0;
            if (s2 > 0) s2 = 0;
        }
        return total == mins ? maxs : max(maxs, total - mins);
    }
};