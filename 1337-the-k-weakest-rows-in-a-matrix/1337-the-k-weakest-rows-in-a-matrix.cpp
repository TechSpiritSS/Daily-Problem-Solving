class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        for (int ii = 0; ii < mat.size(); ++ii)
            pq.push({std::accumulate(mat[ii].begin(), mat[ii].end(), 0), ii});

        std::vector<int> ret;
        while (k > 0 && !pq.empty()) 
        {
            ret.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ret;
        
    }
};