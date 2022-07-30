class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
        if (s.size() < p.size()) return ans;
    
        vector<int> count(26);
        vector<int> slide(26);
        
        for (int i = 0; i < p.size(); ++i)
        {
            ++count[p[i] - 'a'];
            ++slide[s[i] - 'a'];
        }
        
        if (count == slide)
            ans.push_back(0);
        
        for (int i = p.size(), j = 0; i < s.size(); ++i, ++j)
        {
            --slide[s[j] - 'a'];
            ++slide[s[i] - 'a'];
            
            if (slide == count)
                ans.push_back(j + 1);
        }
        return ans;
    }
};
