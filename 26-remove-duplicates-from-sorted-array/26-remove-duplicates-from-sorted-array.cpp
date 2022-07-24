class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        for (int fast = 1; fast < nums.size(); ++fast)
        {
            if (nums[slow] != nums[fast])
            {
                ++slow;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};