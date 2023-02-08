/**
 * @param {number[]} nums
 * @return {number}
 */
var jump = function(nums) {
    let ans = 0, maxi = 0, l = 0;
    for (let i = 0; i < nums.length - 1; ++i)
    {
        maxi = Math.max(maxi, i + nums[i]);
        if (i == l)
        {
            l = maxi;
            ++ans;
        }
    }
    return ans;
};