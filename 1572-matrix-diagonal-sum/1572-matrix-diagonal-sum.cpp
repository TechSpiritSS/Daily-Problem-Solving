class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = n % 2 ? -1 * mat[n / 2][n / 2] : 0;
        
        for (int i = 0; i < n; ++i)
            sum += mat[i][i] + mat[i][n - i - 1];
        
        return sum;
    }
};