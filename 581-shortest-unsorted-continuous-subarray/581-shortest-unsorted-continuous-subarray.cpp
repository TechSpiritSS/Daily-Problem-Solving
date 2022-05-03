class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {        
        int l = 0, r = nums.size() - 1, s = -1, e = -1, min = INT_MAX, max = INT_MIN;
        
        while (r >= 0)
        {
            if (nums[l] < max)
                e = l;
            else
                max = nums[l];
            
            if (nums[r] > min)
                s = r;
            else
                min = nums[r];
            
            ++l, --r;
        }
        
        return s != -1 ? e - s + 1 : 0;
    }
};