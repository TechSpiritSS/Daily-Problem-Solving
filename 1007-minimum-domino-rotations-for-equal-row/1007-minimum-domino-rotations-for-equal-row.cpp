class Solution {
    int check(vector<int> &tops, vector<int> &bottoms, int &common)
    {
        int t = 0;
        int b = 0;
        
        for (int i = 0; i < tops.size(); ++i)
        {
            if (tops[i] == bottoms[i] && tops[i] == common)
                continue;
            
            else if (tops[i] == common)
                ++t;
            
            else if (bottoms[i] == common)
                ++b; 
            else
                return -1;
        }
        
        return min(t, b);
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int ans = check(tops, bottoms, tops[0]);
        
        if (ans == - 1)
            ans = check(tops, bottoms, bottoms[0]);
       
        return ans;
       }
};