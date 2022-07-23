class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minday = INT_MAX, profit = 0;
        
        for (auto &i : prices)
        {
            minday = min(i, minday);
            profit = max(i - minday, profit);
        }
        
        return profit;
    }
};