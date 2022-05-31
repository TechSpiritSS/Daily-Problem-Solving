class Solution {
public:
    bool hasAllCodes(string s, int k) 
    {
        unordered_set<string> combos;
        int n = s.size() - k;
        
        for (int i = 0; i <= n; ++i)
            combos.insert(s.substr(i, k));
        
        return combos.size() == 1 << k;
    }
};