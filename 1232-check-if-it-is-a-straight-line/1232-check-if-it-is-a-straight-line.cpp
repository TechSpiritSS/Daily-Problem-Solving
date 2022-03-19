class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        if (c.size() <= 2)
            return true;
        
        int xd = c[1][0] - c[0][0]; 
        int yd = c[1][1] - c[0][1]; 
        
        for (int i = 2; i < c.size(); ++i) 
        {
            int x1 = c[i][0] - c[0][0];
            int y1 = c[i][1] - c[0][1];
            
            if(x1 * yd != y1 * xd) 
                return false; 
        }
        return true;
    }
};