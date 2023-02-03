/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    if (numRows == 1) return s;
    let n = s.length;
    let sec = 2 * (numRows - 1);
    let ans = "";
    
    for (let c = 0; c < numRows; ++c)
    {
        let i = c;
        
        while (i < n)
        {
            ans += s[i];
            
            if (c != 0 && c != numRows - 1)
            {
                let i2 = i + sec - 2 * c;
                if (i2 < n) ans += s[i2];
            }
            i += sec;
        }
    }
    return ans;
};