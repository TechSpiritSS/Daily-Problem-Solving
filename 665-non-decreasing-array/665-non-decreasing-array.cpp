class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int x  = -1;
        
        if (nums.size() <= 2)
            return true;
        
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i - 1] > nums[i])
            {
                x = i - 1;
                break;
            }
        
        if (x == -1)
            return true;
        
        vector<int> nums2 = nums;
        nums2.erase(nums2.begin() + x);
        nums.erase(nums.begin() + x + 1);
        
        return is_sorted(nums.begin(), nums.end()) || is_sorted(nums2.begin(), nums2.end());
    }
};