class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = lower_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
		int j = i + 1;
		vector<int> ans;

		while (k--)
		{
			if (i >= 0 && j < arr.size())
			{
				if (abs(arr[i] - x) <= abs(arr[j] - x))
				{
					ans.push_back(arr[i]);
					--i;
				}
				else
				{
					ans.push_back(arr[j]);
					++j;
				}
			}
			else if (i >= 0)
			{
				ans.push_back(arr[i]);
				--i;
			}
			else
			{
				ans.push_back(arr[j]);
				++j;
			}
		}
		sort(ans.begin(), ans.end());
		return ans;
    }
};