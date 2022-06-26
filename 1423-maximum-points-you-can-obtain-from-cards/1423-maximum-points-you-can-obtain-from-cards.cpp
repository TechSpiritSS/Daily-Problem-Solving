class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        for (int i = 0; i < k; ++i)
            sum += cardPoints[i];
        
        int ans = sum;
        for (int i = cardPoints.size() - 1, j = k - 1; j >= 0; --i, --j)
        {
            sum -= cardPoints[j];
            sum += cardPoints[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};