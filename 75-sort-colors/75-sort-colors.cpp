class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0, 0, 0};
        
        for (auto &i : nums)
            ++count[i];
        
        for (int i = 0, j = 0; i < 3; ++i)
            while (count[i]--)
                nums[j++] = i;
    }
};