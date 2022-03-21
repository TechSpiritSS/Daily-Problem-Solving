class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        
        unordered_map<char, int> mp;
        
        for (int i = 0; i < n; ++i)
            mp[s[i]] = i;
        
        vector<int> ans;
        
        int curr_max_right = INT_MIN;
        int count = 0;
        
        for (int i = 0; i < n; ++i)
        {
            ++count;
            curr_max_right = max(curr_max_right, mp[s[i]]);
            if (curr_max_right == i)
            {
                ans.push_back(count);
                count = 0;
            }
        }
        
        return ans;
    }
};