class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int prev = 0;
        int ag_prv = 0;
        
        int val;
        for(int i = 2; i <= (int)cost.size(); ++i)
        {
            val = min(prev + cost[i - 1], ag_prv + cost[i - 2]);
            
            ag_prv = prev;
            prev = val;
        }
        
        return val;
    }
};