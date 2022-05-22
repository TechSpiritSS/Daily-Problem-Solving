class Solution {
    bool palindrome(string s)
    {
        int l = 0, r = s.size() - 1;
        
        while (l <= r)
            if (s[l++] != s[r--])
                return false;
        return true;
    }
public:
    int countSubstrings(string s) {
        int ans = 0;
        
        for (int i = 0; i < s.size(); ++i)
        {
            string tmp = "";
            for (int j = i; j < s.size(); ++j)
            {
                tmp += s[j];
                if (palindrome(tmp))
                    ++ans;
            }                
        }
        
        return ans;
    }
};
