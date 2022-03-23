class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> c(26);
        for (char &i : t)
            c[i - 'a']++;
        for (char &i : s)
            c[i - 'a']--;
        
        for (int i = 0; i < 26; ++i)
            if (c[i] != 0)
                return i + 'a';
        
        return ' ';
    }
};