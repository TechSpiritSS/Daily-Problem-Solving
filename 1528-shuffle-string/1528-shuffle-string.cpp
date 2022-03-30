class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector< pair<char, int>> ans;
        
        for (int i = 0; i < indices.size(); ++i)
            ans.push_back({indices[i], s[i]});
        
        sort(ans.begin(), ans.end());
        
        string x = "";
        for (auto &i : ans)
            x += i.second;
        
        return x;
    }
};