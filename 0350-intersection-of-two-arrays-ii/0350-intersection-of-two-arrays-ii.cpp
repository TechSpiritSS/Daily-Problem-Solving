class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int, int> count;
        
        for (auto &x : nums1)
            ++count[x];
        
        for (auto &x : nums2)
            if (count[x])
            {
                res.push_back(x);
                --count[x];
            }
        return res;
    }
};