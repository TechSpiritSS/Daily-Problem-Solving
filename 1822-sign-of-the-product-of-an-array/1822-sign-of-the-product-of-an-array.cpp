class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool n = false;
        for (auto &i : nums)
            if (i < 0) n ^= true;
            else if (i == 0) return 0;
        return n ? -1 : 1;
    }
};