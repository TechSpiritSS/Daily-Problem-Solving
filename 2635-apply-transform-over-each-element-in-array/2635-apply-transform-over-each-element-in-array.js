/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let a = new Array();
    
    arr.forEach((x, i) => {
        a.push(fn(x, i));
    })
    
    return a;
};