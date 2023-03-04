class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) { 
        int nc = mat[0].size(),
            nr = mat.size();
        
        if(nc * nr != r * c)
            return mat;
        
        vector<vector<int>> res(r, vector<int>(c));
        
        int row = 0, col = 0;
        
        for (int i = 0; i < nr; ++i)
            for (int j = 0; j < nc; ++j)
            {
                res[row][col++] = mat[i][j];
                
                if(col == c)
                {
                    col = 0;
                    row++;
                }
            }
        return res;
    }
};