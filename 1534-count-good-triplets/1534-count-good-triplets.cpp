class Solution {
    bool check(int i, int j, int k, int a, int b, int c)
    {
        bool x = abs(i - j) <= a;
        x &= abs(j - k) <= b;
        x &= abs(i - k) <= c;
        return x;
    }
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int ans = 0;
        
        for (int i = 0; i < arr.size(); ++i)
            for (int j = i + 1; j < arr.size(); ++j)
                for (int k = j + 1; k < arr.size(); ++k)
                    if (check(arr[i], arr[j], arr[k], a, b, c))
                        ++ans;
        return ans;
    }
};