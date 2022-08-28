class Solution {
    void Sort(vector<vector<int>> &mat, int row, int col) {
        int r = row;
        int c = col;
        vector<int> v;
        while (r < mat.size() && c < mat[0].size())
        {
            v.push_back(mat[r][c]);
            ++r;
            ++c;
        }

        sort(v.begin(), v.end());

        r = row;
        c = col;
        int i = 0;

        while (r < mat.size() && c < mat[0].size())
        {
            mat[r][c] = v[i];
            ++r;
            ++c;
            ++i;
        }
    }

public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
        for (int row = 1; row < mat.size(); ++row)
            Sort(mat, row, 0);
        for (int col = 0; col < mat[0].size(); ++col)
            Sort(mat, 0, col);
        return mat;
    }
};