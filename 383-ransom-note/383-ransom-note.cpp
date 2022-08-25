class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mag(26);

        for (auto &c : magazine)
            ++mag[c - 'a'];

        for (auto &c : ransomNote)
            if (--mag[c - 'a'] < 0)
                return false;
        
        return true;
    }
};