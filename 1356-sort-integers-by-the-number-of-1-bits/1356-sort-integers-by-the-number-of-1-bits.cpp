class Solution {
    
    static int bits(int x)
    {
        int count = 0;
        while (x)
        {
            if (x & 1)
                ++count;
            x >>= 1;
        }
        
        return count;
    }
    
    static bool cmp(int a, int b)
    {
        if (bits(a) == bits(b))
            return a < b;
        
        if (bits(a) < bits(b))
            return true;
        
        return false;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};