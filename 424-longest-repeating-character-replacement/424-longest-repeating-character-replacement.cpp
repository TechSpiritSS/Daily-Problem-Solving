class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26);
        int l = 0, ans = 0, mfreq = 0;
        
        for (int i = 0; i < s.size(); ++i)
        {
            ++freq[s[i] -'A'];
        
            mfreq = max(mfreq, freq[s[i] -'A']);
            
            if (i - l + 1 - mfreq > k)
            {
                --freq[s[l] - 'A'];
                ++l;
            }
            
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};