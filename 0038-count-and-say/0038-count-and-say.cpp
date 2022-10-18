class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = "11";

        for (int i = 3; i <= n; ++i)
        {
            string tmp = "";
            s = s + ':';
            int cnt = 1;

            for (int j = 1; j < s.size(); ++j)
            {
                if (s[j] != s[j - 1])
                {
                    tmp = tmp + to_string(cnt);
                    tmp = tmp + s[j - 1];
                    cnt = 1;
                }
                else ++cnt;
            }
            s = tmp;
        }
        return s;
    }
};