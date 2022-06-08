class Solution {
    bool palindrome(string s)
    {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
            if (s[i] != s[j])
                return false;
        return true;
    }
public:
    int removePalindromeSub(string s) {
        return palindrome(s) ? 1 : 2;
    }
};