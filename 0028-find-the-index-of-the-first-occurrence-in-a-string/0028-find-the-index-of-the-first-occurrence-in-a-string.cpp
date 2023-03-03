class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        int h = haystack.length();

        if (h < n) return -1;

        vector<int> lcs(n);
        int prev = 0, i = 1;

        while (i < n) 
        {
            if (needle[i] == needle[prev]) 
            {
                ++prev;
                lcs[i] = prev;
                ++i;
            } 
            else 
            {
                if (prev == 0) 
                {
                    lcs[i] = 0;
                    ++i;
                }
                else prev = lcs[prev - 1];
            }
        }

        int hp = 0;
        int np = 0;

        while (hp < h) 
        {
            if (haystack[hp] == needle[np]) 
            {
                ++np;
                ++hp;
                
                if (np == n) return hp - n;        
            } 
            else 
            {
                if (np == 0) ++hp;
                else np = lcs[np - 1];
            }
        }
        
        return -1;
    }
};