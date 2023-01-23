class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusted(n + 1);
        vector<int> trusting(n + 1);
        
        for (auto &i : trust)
        {
            ++trusted[i[0]];
            ++trusting[i[1]];
        }
        
        for (int i = 1; i <=n; ++i)
            if (trusting[i] == n - 1 && trusted[i] == 0)
                return i;
        
        return -1;
    }
};