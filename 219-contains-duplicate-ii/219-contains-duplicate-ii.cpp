class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int, int>> idx;
        
        for (int i = 0; i < nums.size(); ++i)
            idx.push_back({nums[i], i});
        
        sort(idx.begin(), idx.end());
        
        for (int i = 0; i < idx.size() - 1; ++i)   
           if ((idx[i].first == idx[i + 1].first) && (abs(idx[i].second - idx[i + 1].second) <= k))
                return true;
        return false;
    }
};