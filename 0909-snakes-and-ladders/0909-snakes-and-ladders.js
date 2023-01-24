/**
 * @param {number[][]} board
 * @return {number}
 */
var snakesAndLadders = function(board) {
    let n = board.length;
    let target = n * n;
    let b = new Array(n * n + 1);
    let q = [];
    let visited = {};
    
    for (let i = n - 1, k = 1, d = 1; i >= 0; --i, d ^= 1)
    {
        if (d % 2)
            for (let j = 0; j < n; ++j)
                b[k++] = board[i][j];
        else
            for (let j = n - 1; j >= 0; --j)
                b[k++] = board[i][j];
    }
    
    q.push([0, 1]);
    visited[1] = 0;
    
    while (q.length)
    {
        let [dice, curr] = q.shift();
        
        if (visited[curr] && dice >= visited[curr]) continue;
        if (curr == target) return dice;
        visited[curr] = dice;
        
        for (let i = 1; i <= 6; ++i)
        {
            let nxt = curr + i;
            if (nxt > target) continue;
            if (b[nxt] === -1) 
                q.push([dice + 1, nxt]);
            else 
                q.push([dice + 1, b[nxt]]);
        }
        q.sort((x, y) => x[0] - y[0]);
    }
    return -1;
};