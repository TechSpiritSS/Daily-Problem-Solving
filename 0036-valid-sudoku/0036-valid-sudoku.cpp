class Solution {
    bool matrixCheck(vector<vector<char>> &board, int rs, int cs)
    {
        map<char, int> m;
        for (int i = 1; i <= 9; ++i)
            m.insert({(char)(i + '0'), 0});
        
        for (int i = rs; i <= rs + 2; ++i)
            for (int j = cs; j <= cs + 2; ++j)
            {
                if (board[i][j] == '.') 
                    continue;
                
                ++m[board[i][j]];
                if (m[board[i][j]] >= 2)
                    return false;
            }
        return true;
    }
    
    bool checkRow(vector<vector<char>> &board, int m, int n)
    {
        char x = board[m][n];
        if (x == '.') return true;
        
        for (int i = 0; i < 9; ++i)
        {
            if (i == n) continue;
            if (board[m][i] == x)
                return false;
        }
        return true;
    }
    
    bool checkCol(vector<vector<char>> &board, int m, int n)
    {
        char x = board[m][n];
        if (x == '.') return true;
       
        for (int i = 0; i < 9; ++i)
        {
            if (i == m) continue;
            if (board[i][n] == x)
                return false;
        }
        return true;
    }
    
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (short i = 0; i < 9; i += 3)
            for (short j = 0; j < 9; j += 3)
                if (matrixCheck(board, i, j)) continue;
                else return false
                    ;
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (!checkRow(board, i, j) || !checkCol(board, i, j)) 
                    return false;

        return true;
    }
};