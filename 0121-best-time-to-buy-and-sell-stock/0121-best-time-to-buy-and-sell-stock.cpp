class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX,
            maxProfit =INT_MIN;
        
        for (auto &i : prices)
        {
            minPrice = min(minPrice, i);
            maxProfit = max(maxProfit, i - minPrice);
        }
        return maxProfit;
    }
};