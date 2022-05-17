class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> freq;
        
        for (auto &i : nums1)
            freq[i]++;
        
        set<int> s1;
        
        for (auto &i : nums2)
            if (freq[i])
                s1.insert(i);
        
        vector<int> ans;
        
        for (auto &i : s1)
            ans.push_back(i);
        
        return ans;
    }
};