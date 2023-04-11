class Solution {
public:
    string removeStars(string s) {
       string ans = "";
        
        for (auto &i : s)
            if (i == '*') ans.pop_back();
            else ans.push_back(i);
                
        return ans;
    }
};