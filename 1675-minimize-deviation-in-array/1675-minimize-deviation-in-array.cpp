class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> q;
        int m = INT_MAX, ans = INT_MAX;
        
        for (auto &i : nums)
            if (i % 2)
            {
                q.push(i * 2);
                m = min(m, i * 2);
            } 
            else
            {
                q.push(i);
                m = min(m, i);
            }
        
        while (!q.empty())
        {
            int t = q.top();
            q.pop();
            ans = min(ans, t - m);
            if (t % 2) break;
            m = min(m, t / 2);
            q.push(t / 2);
        }
        return ans;
    }
};