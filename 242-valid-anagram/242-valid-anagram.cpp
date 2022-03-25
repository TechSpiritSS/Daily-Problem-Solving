class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] {0};
        
        for (auto &i : s)
            count[i - 'a']++;
        for (auto &i : t)
            count[i - 'a']--;
        
        for (int i = 0; i < 26; ++i)
            if (count[i] != 0)
                return false;
        return true;
    }
};