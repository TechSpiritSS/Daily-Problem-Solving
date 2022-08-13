class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int m = words.size();
        int l = words[0].size();
        
        if (!n || !m || !l)
            return {};
        
        vector<int> ans;
        unordered_map<string, int> mp, mp2;
        
        for (auto &w : words)
            ++mp[w];
        
        for (int i = 0; i <= n - m * l; ++i)
        {
            mp2 = mp;
            for (int j = 0; j <= m; ++j)
            {
                string tmp = s.substr(i + j * l, l);
                if (mp2.find(tmp) == mp2.end()) break;
                
                --mp2[tmp];
                if (mp2[tmp] == 0) mp2.erase(tmp);
                if (mp2.empty()) ans.push_back(i);
            }
        }
        return ans;
    }
};