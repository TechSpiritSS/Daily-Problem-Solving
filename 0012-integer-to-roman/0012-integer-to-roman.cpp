class Solution {
    vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
public:
    string intToRoman(int num) {
        string ans = "";
        
        for (int i = 0; i < value.size(); ++i)
            while (value[i] <= num) {
                ans += symbols[i];
                num -= value[i];
            }
        
        return ans;
    }
};