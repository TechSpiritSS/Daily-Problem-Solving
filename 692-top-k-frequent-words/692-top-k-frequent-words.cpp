class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        map<string, int> f;
        
        for (auto &s : words)
            ++f[s];
        
        vector<pair<string, int>> frq;
        
        for (auto &i : f)
            frq.push_back(i);
        
        sort(frq.begin(), frq.end(), [](const pair<string, int> &l, const pair<string, int> &r)
             {
                if (l.second != r.second) return l.second > r.second;
                return l.first < r.first;
             });
        
        for (auto &i : frq)
        {
            if (k == 0)
                return ans;
            k--;
            ans.push_back(i.first);
        }
        return ans;
    }
};