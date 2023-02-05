class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans, count(26);
        
        for (auto &c : p) ++count[c - 'a'];
        
        int l = 0, r = 0, c = p.size();
        
        while (r < s.size())
        {
            if (count[s[r++] - 'a']-- >= 1) --c;
            if (!c) ans.push_back(l);
            if (r - l == p.size() && count[s[l++] - 'a']++ >= 0) ++c;
        }
        return ans;
    }
};