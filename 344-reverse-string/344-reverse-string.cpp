class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = s.size() - 1;
        
        for(int i = 0; i <= l / 2; ++i)
            swap(s[i], s[l - i]);
    }
};