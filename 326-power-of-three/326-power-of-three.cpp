class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;

        double x = log10(n) / log10(3);
        return ceil(x) == floor(x);
    }
};