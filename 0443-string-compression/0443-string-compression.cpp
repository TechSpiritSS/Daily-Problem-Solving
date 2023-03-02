class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j = 0, ans = 0;
        
        while (i < chars.size())
        {
            char c = chars[i];
            int frq = 0;
            while (i < chars.size() && c == chars[i])
            {
                ++frq;
                ++i;
            }
            
            chars[j++] = c;
            ++ans;
            
            if (frq > 1)
            {
                string x = to_string(frq);
                for (auto &s : x)
                {
                    ++ans;
                    chars[j++] = s;
                }
            }
        }
        return ans;
    }
};