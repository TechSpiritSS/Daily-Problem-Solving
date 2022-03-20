class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = nums.size(), j = 0;
        for (int i = 0; i < l; ++i)
            if (nums[i])
                nums[j++] = nums[i];
        while (j < l)   
            nums[j++] = 0;
    }
};