class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxc = *max_element(candies.begin(), candies.end());
        
        vector<bool> ans;
        for (auto &i : candies)
                ans.push_back(i + extraCandies >= maxc ? true : false);
        
        return ans;
    }
};