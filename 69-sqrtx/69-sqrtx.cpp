class Solution {
public:
    int mySqrt(int x) {
        if (x < 2)
            return x;
        long long int l = 2, h = x, m;
        int ans = 1;
        
        while (l <= h)
        {
            m = (l + h) / 2;
            
            if (m * m == x)
                return m;
            if (m * m < x)
            {
                ans = m;
                l = m + 1;
            }
            if (m * m > x)
                h = m - 1;
        }
        
        return ans;
    }
};