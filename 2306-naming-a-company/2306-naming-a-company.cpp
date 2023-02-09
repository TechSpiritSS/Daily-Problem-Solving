class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;
        unordered_set<string> grp[26];
        
        for (auto &i : ideas)
            grp[i[0] - 'a'].insert(i.substr(1));
        
        for (int i = 0; i < 26; ++i)
            for (int j = i + 1; j < 26; ++j)
            {
                int common = 0;
                
                for (auto &x : grp[i])        
                    if (grp[j].count(x))
                        ++common;
                
                ans += 2 * (grp[i].size() - common) * (grp[j].size() - common);
            }
        return ans;
    }
};