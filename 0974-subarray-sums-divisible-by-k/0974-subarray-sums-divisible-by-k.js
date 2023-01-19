/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraysDivByK = function(nums, k) {
    let ans = 0, pre = 0;
    let mods = new Array(k).fill(0);
    mods[0] = 1;
    
    for (let i of nums)
    {
        pre = (pre + i % k + k) % k;
        ans += mods[pre];
        ++mods[pre];
    }
    return ans;
};