class Solution {
    int shift(vector<vector<int>> &img1, vector<vector<int>> &img2, int x, int y) {
        int left = 0, right = 0;
        int i1Row = 0;
        for (int i2Row = y; i2Row < img2.size(); ++i2Row) {
            int i1Col = 0;
            for (int i2Col = x; i2Col < img2.size(); ++i2Col) {
                if (img2[i2Row][i2Col] == 1 && img2[i2Row][i2Col] == img1[i1Row][i1Col]) ++left;
                if (img2[i2Row][i1Col] == 1 && img2[i2Row][i1Col] == img1[i1Row][i2Col]) ++right;
                ++i1Col;
            }
            ++i1Row;
        }
        return max(left, right);
    }

public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2) {
        int ans = 0;
        for (int y = 0; y < img1.size(); ++y)
            for (int x = 0; x < img1.size(); ++x) {
                ans = max(ans, shift(img1, img2, x, y));
                ans = max(ans, shift(img2, img1, x, y));
            }
        return ans;
    }
};