class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int last = 0, maxval = 0;
        
        for(int i = 0; i < s.size(); ++i)
        {
            char k = s[i];
            if(mp.count(k) > 0)
                last = max(last, mp[k] + 1);
        
            mp[k] = i;
            maxval = max(maxval, i - last + 1);
        }   
        
        return maxval;
    }
};