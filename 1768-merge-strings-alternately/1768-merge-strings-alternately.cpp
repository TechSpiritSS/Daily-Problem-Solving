class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        
        int n = min(word1.size(), word2.size());
        
        for (int i = 0; i < n; ++i)
        {
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }
        
        int x = n;
        
        while (word1[n] != '\0')
            ans.push_back(word1[n++]);
        
        n = x;
        
        while (word2[n] != '\0')
            ans.push_back(word2[n++]);
 
        return ans;
    }
};