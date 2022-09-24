class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
		int maxProfit = 0;

		for (auto &i : prices)
		{
			minPrice = min(minPrice, i);
			maxProfit = max(maxProfit, i - minPrice);
		}
		return maxProfit;    
    }
};