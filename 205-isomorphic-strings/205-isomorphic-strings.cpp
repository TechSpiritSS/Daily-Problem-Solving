class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> smap, tmap;
        
        for (int i = 0; i < s.size(); ++i)
        {
            if (smap[s[i]])
            {
                if (smap[s[i]] != t[i])
                    return false;
            }
        
            else if (tmap[t[i]])
                return false;
        
            else
            {
                smap[s[i]] = t[i];
                tmap[t[i]] = s[i];
            }
        }
        return true;
    }
};