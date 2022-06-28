class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26);
        for (auto &x : s)
            freq[x - 'a']++;
        
        sort(freq.begin(), freq.end(), greater<int>());
        
        int ans = 0;
        int maxF = s.size();
        
        for (int i = 0; i < 26 && freq[i] > 0; ++i)
        {
            if (freq[i] > maxF)
            {
                ans += freq[i] - maxF;
                freq[i] = maxF;
            }
            
            maxF = max(0, freq[i] - 1);
        }
        
        return ans;
    }
};