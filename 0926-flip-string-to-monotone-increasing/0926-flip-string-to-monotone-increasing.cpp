class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans = 0, n1 = 0;
        for (auto &c : s)
            if (c == '0') ans = min(n1, ans + 1);
            else ++n1;
        return ans;
    }
};