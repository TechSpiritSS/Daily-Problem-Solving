class Solution {
public:
    int fib(int n) {
        if (n < 2)
            return n;
        
        int f0 = 0;
        int f1 = 1;
        
        int s = 0;
        
        while (--n)
        {
            s = f1 + f0;
            f0 = f1;
            f1 = s;
        }
        
        return s;
    }
};