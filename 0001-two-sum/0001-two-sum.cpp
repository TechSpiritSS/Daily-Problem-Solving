class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> res;
        int l = nums.size();
        unordered_map<int, int> m;

        for (int i = 0; i < l; ++i)
            m.insert({nums[i], i});

        for (int i = 0; i < l; ++i)
        {
            auto f = m.find(target - nums[i]);
            
            if (f != m.end() && f -> second != i)
            {
                res.push_back(i);
                res.push_back(f -> second);
                return res;
            }
        }
        return res;
    }
};