class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();

		for (int i = 0, j = 0; i < size; ++i, ++j)
		{
			while (s[j] != ' ' && j < size) ++j;
			for (int a = i, b = j - 1; a < b; ++a, --b) swap(s[a], s[b]);
			i = j;
		}
		return s;
    }
};