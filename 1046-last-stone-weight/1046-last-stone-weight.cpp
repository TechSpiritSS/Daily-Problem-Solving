class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 1)
            return stones[0];
        
        sort(stones.begin(), stones.end());
        int &x = stones[stones.size() - 2];
        int &y = stones[stones.size() - 1];
        
        while (x)
        {
            y -= x;
            x = 0;
            sort(stones.begin(), stones.end());
            x = stones[stones.size() - 2];
            y = stones[stones.size() - 1];
        }
        
        return stones[stones.size() - 1];
    }
};