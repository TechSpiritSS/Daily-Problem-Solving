class Solution {
public:
    int maxLen = 0;
    string ans = "";
    void xp(string s, int left, int right) 
    {
        while (left >= 0 && right < s.length() && s[left] == s[right]) 
        {
            if (maxLen < right - left + 1) 
            {
                maxLen = right - left + 1;
                ans = s.substr(left, right - left + 1);
            }
            --left; 
            ++right;
        }
    }
    
    string longestPalindrome(string s) 
    {
        for (int i = 0; i < s.length(); ++i)
        {
            xp(s, i, i);
            xp(s, i, i + 1);
        }
        return ans;    
    }
};