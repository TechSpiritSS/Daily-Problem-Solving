class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> ans;
        for (int i = 0; i < words.size(); ++i)
        {
            string tmp = "";
              for (int j = 0; j < words[i].length(); ++j)
                  tmp += morse[words[i][j] - 'a'];
            ans.insert(tmp);              
        }        
        return ans.size();
    }
};