class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) return n;
        int p1 = 1, p2 = 1, ans = 0;
        while (--n)
        {
            ans = p1 + p2;
            p2 = p1;
            p1 = ans;
        }
        return ans;
    }
};