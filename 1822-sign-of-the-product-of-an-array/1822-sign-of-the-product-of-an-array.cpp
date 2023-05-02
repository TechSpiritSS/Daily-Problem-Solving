class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool negative = false;
        
        for (auto &i : nums)
            if (i < 0) negative ^= true;
            else if (i == 0) return 0;
        
        return negative ? -1 : 1;
    }
};