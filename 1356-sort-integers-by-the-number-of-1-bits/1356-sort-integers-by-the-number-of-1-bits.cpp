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
    
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        if (a.second != b.second)
            return a.second < b.second;   
        return a.first < b.first;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> bit_count;
        
        for (int &i : arr)
            bit_count.push_back({i, bits(i)});
        
   
        sort(bit_count.begin(), bit_count.end(), cmp);
        
        vector<int> ans;
        
        for (pair<int, int> &i : bit_count)
            ans.push_back(i.first);
        
        return ans;
    }
};