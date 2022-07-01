class Solution {
    static bool cmp(vector<int> a, vector<int> b)
    {
        return a[1] > b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int ans = 0;
        
        for (auto &i : boxTypes)
        {
            if (i[0] > truckSize)
                return ans + (truckSize * i[1]);
            ans += (i[0] * i[1]);
            truckSize -= i[0];
        }
        
        return ans;
    }
};