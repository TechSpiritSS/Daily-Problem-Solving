class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = nums.size();       
        for (int i = 0, j = l - 1; i < j;)
        {
            if (nums[i] % 2 > nums[j] % 2) swap(nums[j], nums[i]);
            if (nums[i] % 2 == 0) ++i;
            if (nums[j] % 2) --j;
        }
        return nums;
    }
};