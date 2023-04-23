class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n = 1;
        if (digits.size() == 0) return ans;
        
        unordered_map <int, string> dial;
        dial[2] = "abc";
        dial[3] = "def";
        dial[4] = "ghi";
        dial[5] = "jkl";
        dial[6] = "mno";
        dial[7] = "pqrs";
        dial[8] = "tuv";
        dial[9] = "wxyz";
        
        for (char &c : digits)
            if (c == '7' || c == '9') n *= 4;
            else n *= 3;
        
        ans.resize(n);
        
        for (char &c : digits)
        {
            int p = n / dial[c - '0'].size();
            for (int j = 0; j < ans.size();)
                for (int k = 0; k < dial[c - '0'].size(); ++k)
                {
                    int tmp = p;
                    while (tmp--)
                    {
                        ans[j] += dial[c - '0'][k];
                        ++j;
                    }
                }
            n = p;
        }
        return ans;
    }
};
