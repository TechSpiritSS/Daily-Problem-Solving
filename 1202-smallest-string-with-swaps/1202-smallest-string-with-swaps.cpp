class Solution {
public:
    vector<vector<int>> g;
    vector<bool> visited;
    
    void dfs(int i, vector<char> &letters, vector<int> &idx, string &s)
    {
        visited[i] = true;
        idx.push_back(i);
        letters.push_back(s[i]);
        
        for (int &it: g[i])
            if (!visited[it]) 
                dfs(it, letters, idx, s);
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) 
    {
        int n = s.size();
        g.resize(n);
        visited.resize(n, false);
        
        for (vector<int> &it: pairs)
        {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        
        for (int i = 0; i < n; ++i)
        {
            vector<int> idx;
            vector<char> letters;
            
            if (!visited[i])
                dfs(i, letters, idx, s);
            
            sort(idx.begin(), idx.end());
            sort(letters.begin(), letters.end());
            
            for(int i = 0; i < idx.size(); ++i) 
                s[idx[i]] = letters[i];
        }
        return s;
    }
};