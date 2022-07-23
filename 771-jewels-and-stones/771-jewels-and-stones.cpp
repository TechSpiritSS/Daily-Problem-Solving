class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<bool> chars(125);
        
        for (auto &i : jewels)
            chars[i] = true;
        
        int count = 0;
        
        for (auto &i : stones)
            if (chars[i])
                ++count;
        
        return count;
    }
};