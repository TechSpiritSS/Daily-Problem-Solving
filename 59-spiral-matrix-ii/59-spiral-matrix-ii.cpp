class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int r_st = 0, r_end = n - 1, c_st = 0, c_end = n - 1;
        int val = 0;
    
        vector<vector<int>> v (n, vector<int>(n));
    
        while (r_st <= r_end && c_st <= c_end)
        {
            for (int i = c_st; i <= c_end; ++i)
                v[r_st][i] = ++val;
       
            for (int i = r_st + 1; i <= r_end ;++i) 
                v[i][c_end] = ++val;
       
            for (int i = c_end - 1; i >= c_st; --i)
                v[r_end][i] = ++val;
        
            for (int i = r_end - 1; i > r_st; --i) 
                v[i][c_st] = ++val;
       
            ++r_st;
            ++c_st;
            --r_end;
            --c_end;
        }
    
        return v;
    }
};