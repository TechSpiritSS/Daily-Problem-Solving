class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        for (int i = 0; i < 32; i++)
        {
            int x = 1 << i;
            string t = to_string(x);
            sort(t.begin(), t.end());
            if (s == t)
                return true;
        }
        return false;
    }
};