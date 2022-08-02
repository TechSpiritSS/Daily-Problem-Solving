class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> p;
        
        for (auto &i : matrix)
            for (auto &j : i)
            {
                p.push(j);
                if (p.size() > k) p.pop();
            }
        return p.top();
    }
};