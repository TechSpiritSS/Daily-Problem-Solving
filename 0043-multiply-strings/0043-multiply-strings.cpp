class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
    
        int n = num1.size() + num2.size();
        string ans(n, '0');
        
        for (int i = 0; i < num2.size(); ++i)
        {
            int d2 = num2[i] - '0';
            for (int j = 0; j < num1.size(); ++j)
            {
                int d1 = num1[j] - '0';
                int zero = i + j;
                int carry = ans[zero] - '0';
                int mult = d1 * d2 + carry;
                
                ans[zero] = (mult % 10) + '0';
                ans[zero + 1] += (mult / 10);
            }
        }
        if (ans.back() == '0') ans.pop_back();
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};