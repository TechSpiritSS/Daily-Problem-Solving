class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xors = nums.size();
        for (int i = 0; i < nums.size(); ++i) xors ^= i ^ nums[i];
        return xors;
    }
};