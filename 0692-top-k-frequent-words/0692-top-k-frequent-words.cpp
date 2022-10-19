class Solution {    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> f;
        for (auto &s : words) ++f[s];
        
        sort(words.begin(), words.end(), [&f](string &a, string&b) {
                 if (f[a] > f[b]) return true;
                 if (f[a] < f[b]) return false;
                 return a < b;
             });
        
        unique(words.begin(), words.end());       
        return vector<string> (words.begin(), words.begin() + k);
    }
};