class Solution {
	vector<int> ans;
	void solve(string s, int n, int k, int lastDigit) {
		if (s.size() == n)
		{
			ans.push_back(stoi(s));
			return;
		}

		for (int i = 0; i <= 9; ++i)
			if (abs(i - lastDigit) == k)
			{
				s += to_string(i);
				solve(s, n, k, i);
				s.pop_back();
			}
	}

public:
	vector<int> numsSameConsecDiff(int n, int k) {
		for (int i = 1; i <= 9; ++i)
		{
			string s = to_string(i);
			int lastDigit = i;
			solve(s, n, k, lastDigit);
		}

		return ans;
	}
};