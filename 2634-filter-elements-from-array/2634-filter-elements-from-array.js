/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let a = new Array();
    
    arr.forEach((x, i) => {
        if (fn(x, i))
            a.push(x);
    })
    return a;
};