class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> nums(10);
        int bulls = 0, cows = 0;
        
        for (int i = 0; i < guess.size(); ++i)
            if (guess[i] == secret[i])
                ++bulls;
            else
            {
                if (nums[secret[i] -'0']++ < 0) ++cows;
                if (nums[guess[i] - '0']-- > 0) ++cows;
            }
                    
        string ans = to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};