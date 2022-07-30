class Solution {
    vector<int> count(string s)
    {
        vector<int> ans(26);
        
        for (auto &i : s)
            ++ans[i - 'a'];
        
        return ans;
    }
    
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> max2(26);
        
        for (auto &w : words2)
        {
            vector<int> count2 = count(w);
            for (int i = 0; i < 26; ++i)
                max2[i] = max(max2[i], count2[i]);
        }
        
        vector<string> ans;
        
        for (auto &w : words1)
        {
            bool flag = true;
            vector<int> count1 = count(w);
            
            for (int i = 0; i < 26; ++i)
                if (count1[i] < max2[i])
                    flag = false;
            
            if (flag) ans.push_back(w);
        }
        return ans;
    }
};