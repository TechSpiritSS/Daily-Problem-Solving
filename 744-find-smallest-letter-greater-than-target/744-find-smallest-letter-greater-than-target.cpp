class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int st = 0, end = letters.size() - 1;
        int m = end / 2;
        
        while (st < end)
        {
            if (letters[m] > target)
                end = m;
            else
                st = m + 1;
            m = (end + st) / 2;
        }
        
        if (letters[st] > target)
            return letters[st];
        
        return letters[0];
    }
};