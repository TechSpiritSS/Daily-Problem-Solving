class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> count;
        
        for (int &i : nums)
            ++count[i];
        
        int ans = 0;
        
        for (auto &x : count)
        {
            int i = x.first;
            while (count[i] > 0)
            {
                count[i]--;
                if (count.find(k - i) != count.end() && count[k - i] > 0)
                {
                    count[k - i]--;
                    ++ans;
                }
            }
        }
        
        return ans;
    }
};