class Solution {
public:
    void helper(string &s)
    {
        int i = 0;
        while (i < s.size())
        {
            if (s[i] == '#')
            {
                if (i == 0)
                    s.erase(0, 1);
                else 
                {
                    s.erase(i - 1, 2);
                    --i;
                }
                continue;
            }
            ++i;
        }
    }
    bool backspaceCompare(string s, string t) 
    {
        helper(s);
        helper(t);
        
        if (s.size() != t.size())
            return false;
        
        for (int i = 0; i < s.size(); ++i)
            if (s[i] != t[i])
                return false;
        
        return true;
    }
};