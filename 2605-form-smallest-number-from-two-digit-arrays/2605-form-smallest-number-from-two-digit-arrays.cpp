class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        vector<int> frq(10);
        sort(nums2.begin(), nums2.end());
        
        for (auto &i : nums1) ++frq[i];
        for (auto &i : nums2) if (frq[i]) return i;
        
        int a = *min_element(nums1.begin(), nums1.end()),
            b = nums2[0];
    
        if (a < b) return a * 10 + b;
        return b * 10 + a;
    }
};