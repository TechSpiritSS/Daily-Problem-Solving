class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> n(26);
        
        for (auto &c : s) ++n[c - 'a'];
        for (auto &c : t) --n[c - 'a'];
        
        for (auto &c : n) 
            if (c != 0)
                return false;
        
        return true;
    }
};