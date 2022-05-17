class Solution {
public:
    int tribonacci(int n) {
        int fibo[38] = {0, 1, 1};
        
        for (int i = 3; i <= n; ++i)
            fibo[i] = fibo[i - 1] + fibo[i - 2] + fibo[i - 3];
        
        return fibo[n];
    }
};