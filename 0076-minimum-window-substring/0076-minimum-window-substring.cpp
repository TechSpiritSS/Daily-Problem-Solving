class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128);
        for (char c : t) ++freq[c];
        int l = 0, r = 0, minLen = INT_MAX, start = 0, count = t.size();

        while (r < s.size())
        {
            if (--freq[s[r++]] >= 0) --count;

            while (count == 0)
            {
                if (r - l < minLen)
                {
                    minLen = r - l;
                    start = l;
                }
                if (++freq[s[l++]] > 0) ++count;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};