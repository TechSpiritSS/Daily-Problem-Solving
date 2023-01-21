class Solution {
    bool ok(string s) 
    {
        if (s.size() > 3 || 
            s.size() == 0 ||
            (s[0] == '0' && s.size() > 1) || 
            stoi(s) > 255
           ) return false;
        return true;
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int n = s.size();

        for (int i = 1; i < 4 && i < n; i++)
            for (int j = i + 1; j < i + 4 && j < n; j++) 
                for (int k = j + 1; k < j + 4 && k < n; k++) 
                {
                    string seg1 = s.substr(0, i),
                           seg2 = s.substr(i, j - i),
                           seg3 = s.substr(j, k - j), 
                           seg4 = s.substr(k);
                    
                    if (ok(seg1) && ok(seg2) && ok(seg3) && ok(seg4))
                        ans.push_back(seg1 + "." + seg2 + "." + seg3 + "." + seg4);
                }
        return ans;
    }
};
