class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() > t.size())
            return false;
        
        int i = -1;
        for (auto &c : s)
        {
            ++i;
            for (; i < t.size(); ++i)  
                if (c == t[i])
                    break;
            if (i == t.size())
                return false;
        }    
        return true;
    }
};