class Solution {
    int first(vector<int>& nums, int target){
        int s = 0, e = nums.size() - 1, m = nums.size() / 2;
        
        while (s <= e)
        {
            if (nums[m] < target)
                s = m + 1;
            else if (nums[m] > target)
                e = m - 1;
            else if (m == 0 || nums[m - 1] < nums[m])
                return m;
            else
                e = m - 1;
            m = s + (e - s) / 2;
        }
        return -1;
    }
    
    int last(vector<int>& nums, int target){
        int s = 0, e = nums.size() - 1, m = nums.size() / 2;
        
        while (s <= e)
        {
            if (nums[m] < target)
                s = m + 1;
            else if (nums[m] > target)
                e = m - 1;
            else if (m == nums.size() - 1 || nums[m + 1] > nums[m])
                return m;
            else
                s = m + 1;
            m = s + (e - s) / 2;
        }
        return -1;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        ans[0] = first(nums, target);
        ans[1] = last(nums, target);
        
        return ans;
    }
};