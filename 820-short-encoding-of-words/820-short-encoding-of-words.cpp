class Solution {
    static bool cmp(string &a,string &b)
    {
        return a.length() > b.length();
    }
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        unordered_set<string> s1;
        int ans = words[0].size() + 1;
        string tmp = words[0];
        
        while (tmp.size() > 0)
        {
            s1.insert(tmp);
            tmp.erase(0, 1);
        }
        
        for (int i = 1; i < words.size(); ++i)
        {
            if (s1.find(words[i]) == s1.end())
            {
                ans += words[i].size() + 1;
                tmp = words[i];
                while (tmp.size())
                {
                    s1.insert(tmp);
                    tmp.erase(0, 1);
                }
            }
        }
        return ans;
    }
};