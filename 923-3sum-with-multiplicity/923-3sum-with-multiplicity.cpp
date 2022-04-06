class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, int> cnt;
        
        for (int &a : arr)
            ++cnt[a];
        long ans = 0;
        
        for (auto &l1 : cnt)
            for (auto &l2 : cnt)
            {
                int i = l1.first, j = l2.first, k = target - i - j;
                
                if (!cnt.count(k))
                    continue;
                
                if (i == j && j == k)
                    ans += cnt[i] * long(cnt[i] - 1) * (cnt[i] - 2) / 6;
                
                else if (i == j && j != k)
                    ans += cnt[i] * (cnt[i] - 1) / 2 * cnt[k];
                
                else if (i < j && j < k)
                    ans += cnt[i] * cnt[j] * cnt[k];
            }
        
        return ans % int(1e9 + 7);
    }
};