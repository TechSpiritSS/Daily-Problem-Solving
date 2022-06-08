class Solution {
    bool a = false, b = false;
    bool palindrome(string s)
    {
        int n = s.size() - 1;
        for (int i = 0, j = n; i < j; ++i, --j)
        {
            if (s[i] == 'a' || s[j] == 'a')
                a = true;
            if (s[i] == 'b' || s[j] == 'b')
                b = true;
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
public:
    int removePalindromeSub(string s) {
        if (palindrome(s))
            return 1;
        
        if (a & b)
            return 2;
        return 1;
    }
};