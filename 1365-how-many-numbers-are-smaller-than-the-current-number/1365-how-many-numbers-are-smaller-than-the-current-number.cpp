class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101);
        
        for (auto &i : nums)
            ++count[i];
        
        for (int i = 1; i < 101; ++i)
            count[i] += count[i - 1];
        
        vector<int> ans;
        
        for (auto &i : nums)
            if (i > 0)
                ans.push_back(count[i - 1]);
            else
                ans.push_back(0);
        
        return ans;
    }
};