class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        
        for (int i = 0; i < n; ++i)
            ans += 'a';
        
        k -= n;
        int i = n - 1;
        
        while (k)
        {
            if (k - 26 >= 0)
            {
                ans[i] = 'z';
                k -= 25;
                --i;
            }
            
            if (k < 26)
            {
                ans[i] += k;
                k = 0;
            }
        }
        
        return ans;
    }
};