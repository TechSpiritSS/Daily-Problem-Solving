class Solution {
    bool check(vector<int> &t, long long x, int tt)
    {
        long long c = 0;
        for (auto &i : t)
            c += x / i;
        
        return c >= tt;
    }
    
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1LL,
                  r = 1LL * *max_element(time.begin(), time.end()) * totalTrips;
        
        while (l < r)
        {
            long long mid = (l + r) / 2;
            if (check(time, mid, totalTrips))
                r = mid;
            else l = mid + 1;
        }
        return l;
    }
};