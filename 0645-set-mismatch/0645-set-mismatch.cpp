class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> arr(nums.size() + 1);

        for (auto &i : nums) ++arr[i];

        vector<int> ans;
        int m = -1;
        for (int i = 1; i <= nums.size(); ++i)
        {
            if (arr[i] == 2) ans.push_back(i);
            else if (arr[i] == 0) m = i;
        }
        
        ans.push_back(m);
        return ans;
    }
};