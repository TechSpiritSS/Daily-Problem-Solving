class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) 
            return INT_MAX;
        
        if (dividend == INT_MIN && divisor == 1) 
            return INT_MIN;
        
        long int dd = abs(dividend), dv = abs(divisor);
        
        int ans = 0;
        
        while (dv <= dd)
        {
            long int m = dv, tmp = 1;
            while (m <= dd - m)
            {
                m += m;
                tmp += tmp;
            }
            ans += tmp;
            dd -= m;
        }
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            return -ans;
        return ans;
    }
};