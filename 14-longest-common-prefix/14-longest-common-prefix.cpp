class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min = strs[0].size();
        string ans = "";
        
        for (auto &s : strs)
            for (int i = 0; i < min; ++i)
                if (s[i] != strs[0][i])
                {
                    min = i;
                    break;
                }
        for (int i = 0; i < min; ++i)
            ans += strs[0][i];
        
        return ans;
    }
};
