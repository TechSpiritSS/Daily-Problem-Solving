class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int target = n * n;
        vector<int> b(n * n + 1);
        
        for (int i = n - 1, k = 1, d = 1; i >= 0; --i, d ^= 1)
        {
            if (d % 2)
                for (int j = 0; j < n; ++j)
                    b[k++] = board[i][j];
            else
                for (int j = n - 1; j >= 0; --j)
                    b[k++] = board[i][j];
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 1});
        unordered_map<int, int> visited;
        
        while (!q.empty())
        {
            auto [dice, curr] = q.top();
            q.pop();
            if (visited.count(curr) && dice >= visited[curr]) continue;
            if (curr == target) return dice;
            visited[curr] = dice;
            
            for (int i = 1; i <= 6; ++i)
            {
                int nxt = curr + i;
                if (nxt > target) continue;
                if (b[nxt] == -1)
                    q.push({dice + 1, nxt});
                else
                    q.push({dice + 1, b[nxt]});
            }
        }
        return -1;
    }
};