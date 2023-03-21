class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0,
                  subs = 0;
        
        for (auto &i : nums)
        {
            if (i) subs = 0;
            else ++subs;
            
            ans += subs;
        }
        return ans;
    }
};