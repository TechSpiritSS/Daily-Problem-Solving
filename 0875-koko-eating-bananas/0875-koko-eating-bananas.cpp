class Solution {
    long long solve(vector<int> &p, int m)
    {
        long long t = 0;
        for (auto &i : p)
            t += (long)(i + m - 1) / m;
        
        return t;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = -1,
            l = 1, 
            r = *max_element(piles.begin(), piles.end());
        
        while (l <= r)
        {
            int m = (l + r) / 2;
            long long t = solve(piles, m);
            
            if (t <= h)
            {
                ans = m;
                r = m - 1;
            } else
                l = m + 1;
        }
        return ans;
    }
};