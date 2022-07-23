class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> m;
        
        for (int i = 0;  i < nums.size(); ++i)
            m[nums[i]] = i;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            auto x = m.find(target - nums[i]);
            if (x != m.end() && x -> second != i)
            {
                ans.push_back(i);
                ans.push_back(x -> second);
                break;
            }
        }
        return ans;
    }
};