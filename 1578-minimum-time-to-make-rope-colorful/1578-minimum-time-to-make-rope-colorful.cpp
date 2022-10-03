class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int total = 0, currMax = 0;

		for (int i = 0; i < colors.size(); ++i)
		{
			if (i && colors[i] != colors[i - 1]) currMax = 0;
			total += min(currMax, neededTime[i]);
			currMax = max(currMax, neededTime[i]);
		}
		return total;
    }
};