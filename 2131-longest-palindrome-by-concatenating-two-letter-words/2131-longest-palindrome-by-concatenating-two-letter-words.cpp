class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> same, diff;
        int ans = 0;
        
        for (auto &s : words)
        {
            if (s[0] == s[1]) ++same[s]; 
            else ++diff[s];
        }
        
        string tmp;
        int max = 0;
        
        for (auto &i : same)
        {
            ans += 4 * (i.second / 2);
            if (i.second > max)
            {
                max = i.second;
                tmp = i.first;
            }
        }
        
        if (max % 2) ans += 2;
        else
            for (auto &i : same)
                if (i.first != tmp && i.second % 2)
                {
                    ans += 2;
                    break;
                }
        for (auto &i : diff)
        {
            string rev = i.first;
            swap(rev[0], rev[1]);
            
            if (diff.find(rev) != diff.end())
            {
                ans += 4 * min(diff[i.first], diff[rev]);
                diff[i.first] = 0;
                diff[rev] = 0;
            }
        }
        
        return ans;
    }
};
		