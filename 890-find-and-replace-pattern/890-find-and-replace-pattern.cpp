class Solution {
    bool same(string word, string pattern)
    {
        map<char, char> m;
        
        for (int i = 0; i < word.size(); ++i)
        {
            if (m.find(word[i]) == m.end())
                m[word[i]] = pattern[i];
            
            if (m[word[i]] != pattern[i])
                return false;
        }
        
        vector<bool> dup(26);
        for (auto &p : m)
        {
            if (dup[p.second - 'a']) 
                return false;
            dup[p.second - 'a'] = true; 
        }
        return true;
    }
    
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (auto &w : words)
            if (same(w, pattern))
                ans.push_back(w);
        
        return ans;
    }
};