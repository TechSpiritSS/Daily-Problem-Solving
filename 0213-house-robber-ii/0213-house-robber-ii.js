/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    if (nums.length < 2) return nums[0];
    
    let c1 = nums[0], c2 = nums[1];
    let p1 = 0, p2 = 0;
    
    for (let i = 2; i < nums.length; ++i)
    {
        let t1 = Math.max(c1, p1 + nums[i - 1]);
        let t2 = Math.max(c2, p2 + nums[i]);
        
        p1 = c1, p2 = c2;
        c1 = t1, c2 = t2;
    }
    
    return Math.max(c1, c2);
};