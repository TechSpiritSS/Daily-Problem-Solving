class Solution {
public:
    int mod = 1000000007;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0); 
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0); 
        verticalCuts.push_back(w); 
        
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        long long hmax = 0,vmax = 0;
        for (int i = 0; i < n - 1; ++i)
            hmax = (max(hmax, (long long)horizontalCuts[i + 1] - horizontalCuts[i])) % mod;
        

        for (int i = 0;i < m - 1; ++i)
            vmax = (max(vmax, (long long)verticalCuts[i + 1] - verticalCuts[i])) % mod;
        
        
        long long ans = (hmax * vmax) % mod;
        return ans;
    }
};