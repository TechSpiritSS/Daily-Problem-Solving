class Solution {
    vector<int> n1, n2;
    
    bool check()
    {
        return n1 == n2;
    }
    
public:
    bool checkInclusion(string s1, string s2) {
        int s = s1.size(), l = s2.size();
        n1.resize(26);
        n2.resize(26);
        
        for (auto &i : s1)
            ++n1[i - 'a'];
    
        int i = 0;
        for (; i < l && i < s; ++i)
            ++n2[s2[i] - 'a'];
        
        if (check()) return true;
        
        while (i < l)
        {
            --n2[s2[i - s] - 'a'];
            ++n2[s2[i] - 'a'];
            
            if (check()) return true;
            ++i;
        }
        return false;
    }
};
