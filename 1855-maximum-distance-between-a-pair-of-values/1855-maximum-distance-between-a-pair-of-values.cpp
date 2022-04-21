class Solution {
    int bs(vector<int> &num, int x, int s)
    {
        int e = num.size() - 1;
        
        while (s <= e)
        {
            int m = s + (e - s) / 2;
            
            if (num[m] >= x)
                s = m + 1;
            else
                e = m - 1;
        }
        return s;
    }
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for (int i = 0; i < nums1.size(); ++i)
        {
            int j = bs(nums2, nums1[i], i);
            ans = max(ans, j - i - 1);
        }
        
        return ans;
    }
};