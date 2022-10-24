class Solution {
public:
	int lengthOfLongestSubstring(string s)
	{
		unordered_map<char, int> frq;
		int start = 0, ans = 0;

		for (int i = 0; i < s.size(); ++i)
		{
			if (frq.count(s[i]))  start = max(start, frq[s[i]] + 1);

			frq[s[i]] = i;
			ans = max(ans, i - start + 1);
		}
		return ans;
	}
};