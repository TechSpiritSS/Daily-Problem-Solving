class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> pos(26);
        
        for (int i = 0; i < s.size(); ++i)
            pos[s[i] - 'a'].push_back(i);
        
        int ans = words.size();
        
        for (auto &i : words)
        {
            int idx = -1;
            
            for (auto &c : i)
            {
                auto &p = pos[c - 'a'];
                auto it = upper_bound(p.begin(), p.end(), idx);
                
                if (it == p.end())
                {
                    --ans;
                    break;
                }
                
                idx = *it;
            }
        }
        return ans;
    }
};