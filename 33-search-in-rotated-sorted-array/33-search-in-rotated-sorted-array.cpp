class Solution {
    int BS(vector<int>& nums, int target, int s, int e)
    {
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            
            if (nums[m] == target)
                return m;
            else if (nums[m] > target)
                e = m - 1;
            else
                s = m + 1;
        }
        return -1;
    }
    int searcher(vector<int>& nums, int target, int s, int e)
    {
        if (s > e)
            return -1;
        if (nums[s] < nums[e])
            return BS(nums, target, s, e);
        int m = s + (e - s) / 2;
        
        if (nums[m] == target)
            return m;
        return max(searcher(nums, target, s, m - 1), searcher(nums, target, m + 1, e));
    }
public:
    int search(vector<int>& nums, int target) {
        return searcher(nums, target, 0, nums.size() - 1);
    }
};