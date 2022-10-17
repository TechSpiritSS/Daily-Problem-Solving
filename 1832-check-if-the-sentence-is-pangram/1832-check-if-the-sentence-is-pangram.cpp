class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool arr[26] = {0};
        for (auto &i : sentence) arr[i - 'a'] = true;
        
        bool ans = true;
        for (auto &i : arr) ans &= i;
        return ans;
    }
};