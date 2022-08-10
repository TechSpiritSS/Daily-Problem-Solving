class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int n = matrix[0].size(), s = 0;
        int e = (matrix.size() * n) - 1;

        while (s <= e)
        {
            int mid = (s + e) / 2;
            int cur = matrix[mid / n][mid % n];

            if (cur == target)
                return true;
            else if (cur < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return false;
    }
};