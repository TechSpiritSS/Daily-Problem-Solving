// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long s = 0, e = n;
        long long ans = 1;
        
        while (s <= e)
        {
            long long m = (s + e) / 2;
            
            if (isBadVersion(m))
            {
                ans = m;
                e = m - 1;
            }
            else
                s = m + 1;
        }
        return ans;
    }
};