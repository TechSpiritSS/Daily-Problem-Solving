class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> n(nums.begin(), nums.end());
        return !(n.size() == nums.size());
    }
};