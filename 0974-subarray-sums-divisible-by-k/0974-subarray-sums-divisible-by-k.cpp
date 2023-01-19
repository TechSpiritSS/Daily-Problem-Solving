class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0, pre = 0;
        vector<int> mod(k);
        mod[0] = 1;
        
        for (auto &i : nums)
        {
            pre = (pre + i % k + k) % k;
            ans += mod[pre];
            ++mod[pre];
        }
        return ans;
    }
};