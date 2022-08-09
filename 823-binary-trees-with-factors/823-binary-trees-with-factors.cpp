class Solution{
    int mod = 1e9 + 7;

public:
    int numFactoredBinaryTrees(vector<int> &arr){
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<long long> dp(n, 1);

        map<int, int> pos;

        for (int i = 0; i < n; ++i)
            pos[arr[i]] = i;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (arr[i] % arr[j] == 0)
                {
                    int x = arr[i] / arr[j];
                    if (pos.find(x) != pos.end())
                        dp[i] = (dp[i] + (dp[j] * dp[pos[x]]) % mod) % mod;
                }
        long ans = 0;
        for (auto &i : dp)
            ans = (ans + i) % mod;

        return ans;
    }
};
