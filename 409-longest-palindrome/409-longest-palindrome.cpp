class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> chars;
        
        for (auto &i : s)
            chars[i]++;
        
        bool odd = false;
        int ans = 0;
        
        for (auto &i : chars)
        {
            if (i.second % 2)
            {
                odd = true;
                ans += i.second - 1;
            }
            else
                ans += i.second;
        }
        
        return odd ? ans + 1 : ans;
    }
};