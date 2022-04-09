class Solution {
public:
    static bool cmp (const pair<int, int> &p1, const pair<int, int> &p2) {
	    return p1.second > p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for (auto i : nums)
                ++freq[i];
            
        vector< pair<int, int>> vec(freq.begin(), freq.end());
        sort(vec.begin(), vec.end(), cmp);
        
        vector<int> ans;
        
        for (int i = 0; i < k; ++i)
            ans.push_back(vec[i].first);
        
        return ans;
    }
};