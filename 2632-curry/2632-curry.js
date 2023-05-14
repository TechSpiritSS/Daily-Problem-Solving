/**
 * @param {Function} fn
 * @return {Function}
 */
var curry = function(fn) {
    let arr = new Array();
    return function curried(...args) {
        arr.push(...args);
        if (arr.length < fn.length) return curried;
        return fn(...arr);
    };
};

/**
 * function sum(a, b) { return a + b; }
 * const csum = curry(sum);
 * csum(1)(2) // 3
 */
