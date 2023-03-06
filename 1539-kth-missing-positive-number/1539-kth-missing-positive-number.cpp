class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s = 0,
            e = arr.size();
    
        while (s < e)
        {
            int m = (s + e) / 2;

            if (arr[m] - (m + 1)  >= k)
                e = m;
            else s = m + 1;
        }
        return s + k;
    }
};