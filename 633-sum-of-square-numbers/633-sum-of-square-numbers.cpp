class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long i = 0; i * i <= c; ++i)
        {
            double x = sqrt(c - (i * i));
            if (x == int (x))
                return true;
        }
        return false;
    }
};