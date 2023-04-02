class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        
        int n = potions.size(),
            maxp = potions[n - 1];
        
        for (auto &i : spells)
        {
            long long minp = ceil((1.0 * success) / i);
            
            if (minp > maxp) 
            {
                ans.push_back(0);
                continue;
            }
            
            auto x = lower_bound(potions.begin(), potions.end(), minp) - potions.begin();
            ans.push_back(n - x);
        }
        return ans;
    }
};