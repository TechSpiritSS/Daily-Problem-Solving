class Solution {
    int digitSum(int n)
    {
        int sum = 0;
        
        while (n)
        {
            int x = (n % 10);
            n /= 10;
            sum += (x * x);
        }
        
        return sum;
    }
    
public:
    bool isHappy(int n) {
        set<int> s;
        
        while (n != 1 && s.find(n) == s.end())
        {
            s.insert(n);
            n = digitSum(n);
        }
        
        return n == 1;
    }
};