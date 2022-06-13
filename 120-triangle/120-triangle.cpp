class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size() - 2; //2nd last ROW
        
        for (int i = n; i >= 0; --i)
            for (int j = 0; j < triangle[i].size(); ++j)
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);        
        return triangle[0][0];
    }
};