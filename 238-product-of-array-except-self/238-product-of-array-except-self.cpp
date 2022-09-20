class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
		int tmp = 1;

		for (auto &i : nums)
		{
			ans.push_back(tmp);
			tmp *= i;
		}

		tmp = 1;
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			ans[i] *= tmp;
			tmp *= nums[i];
		}

		return ans;
    }
};