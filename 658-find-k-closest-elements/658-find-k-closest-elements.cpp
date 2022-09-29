class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
		while (k--)
		{
            auto it = lower_bound(arr.begin(), arr.end(), x);
			if (it == arr.begin())
			{
				ans.push_back(arr[0]);
				arr.erase(arr.begin());
			}
			else if (it == arr.end())
			{
				ans.push_back(arr.back());
				arr.pop_back();
			}
			else
			{
				if (x - *(it - 1) <= *it - x)
				{
					ans.push_back(*(it - 1));
					arr.erase(it - 1);
				}
				else
				{
					ans.push_back(*it);
					arr.erase(it);
				}
			}
		}
		sort(ans.begin(), ans.end());
		return ans;
    }
};