class Solution {
    
    int total;
    int queen[10];

    bool check(int lvl, int col)
    {
        for (int i = 0; i < lvl; ++i)
        {
            int pcol = queen[i];
            if (pcol == col || abs(i - lvl) == abs(col - pcol))
                return false;
        }
        return true;
    }

    int rec(int lvl)
    {
        if (lvl == total) return 1;
        int ans = 0;

        for (int i = 0; i < total; ++i)
            if (check(lvl, i))
            {
                queen[lvl] = i;
                ans += rec(lvl + 1);
                queen[lvl] = -1;
            }

        return ans;
    }
    
public:
    int totalNQueens(int n) {  
        total = n;
        return rec(0);
    }
};