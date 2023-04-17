class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxc = *max_element(candies.begin(), candies.end()),
            n = candies.size();
        vector<bool> ans(n);
        
        for (int i = 0; i < n; ++i)
            if (candies[i] + extraCandies >= maxc)
                ans[i] = true;
        
        return ans;
    }
};