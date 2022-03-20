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
        int common = 0;
        int common2 = 0;
        
        if (tops[0] == tops[1] || tops[0] == bottoms[1])
            common = tops[0];
        
        if (bottoms[0] == tops[1] || bottoms[0] == bottoms[1])
            common2 = bottoms[0];
        
        bool both = false;
        
        if (common && common2)
            both = true;
        
        else if (common2)
            common = common2;
        
        
        int ans = check(tops, bottoms, common);
        int ans2 = -1;
        
        if (both)
            ans2 = check(tops, bottoms, common2);
       
        if (ans2 == -1)
            return ans;
        
        if (ans == -1)
            return ans2;
        
        return min(ans, ans2);
    }
};