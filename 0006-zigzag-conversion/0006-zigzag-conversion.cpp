class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        string ans;
        int n = s.size(), sec = 2 * (numRows - 1);
        
        for (int c = 0; c < numRows; ++c)
        {
            int i = c;
            while (i < n)
            {
                ans += s[i];
                if (c != 0 && c != numRows - 1)
                {
                    int i2 = i + sec - 2 * c;
                    
                    if (i2 < n) ans += s[i2];
                }
                i += sec;
            }
        }
        return ans;
    }
};