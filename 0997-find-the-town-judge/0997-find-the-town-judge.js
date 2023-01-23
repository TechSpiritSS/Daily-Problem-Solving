/**
 * @param {number} n
 * @param {number[][]} trust
 * @return {number}
 */
var findJudge = function(n, trust) {
    let trusts = Array(n + 1).fill(0);
    for (let [a, b] of trust)
    {
        trusts[a] = NaN;
        ++trusts[b];
    }
    return trusts.indexOf(n - 1) || 1;
};