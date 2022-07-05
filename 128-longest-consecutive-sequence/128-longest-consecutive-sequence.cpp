class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> x;
        for (auto &i : nums)
            x.insert(i);
        
        int a, l = 0, ans = 0;
        
        for (auto &it : x)
        {
            if (l == 0)
                l = 1;
            
            else
            {
                if (a + 1 == it)
                    ++l;
                else
                {
                    ans = max(ans, l);
                    l = 1;
                }
            }
            a = it;
        }
        return max(ans, l);
    }
};