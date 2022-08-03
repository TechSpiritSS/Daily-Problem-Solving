class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int sr = 0, sc = 0, er = matrix.size() - 1, ec= matrix[0].size() - 1;
        int size = (er + 1) * (ec + 1);
        
        while (ans.size() < size)
        {
            for (int i = sc; i <= ec; ++i)
                ans.push_back( matrix[sr][i] );
            ++sr;
            
            if (ans.size() >= size) break;
            
            for (int i = sr; i <= er; ++i)
                ans.push_back( matrix[i][ec] );
            --ec;
            
            if (ans.size() >= size) break;
            
            for (int i = ec; i >= sc; --i)
                ans.push_back( matrix[er][i] );
            --er;
            
            if (ans.size() >= size) break;
            
            for (int i = er; i >= sr; --i)
                ans.push_back( matrix[i][sc] );
            ++sc;
        }
        return ans;
    }
};