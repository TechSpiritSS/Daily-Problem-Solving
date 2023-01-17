/**
 * @param {string} s
 * @return {number}
 */
var minFlipsMonoIncr = function(s) {
    let ans = 0, n1 = 0;
    for (let i of s)
        if (i === '0') ans = Math.min(n1, ans + 1);
        else ++n1;
    return ans;
};