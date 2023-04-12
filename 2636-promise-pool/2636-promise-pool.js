/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
var promisePool = async function(functions, n) {
    let i = 0;
    
    const fun = async() => {
        const x = i;
        ++i;
        
        if (x >= functions.length) return;
        
        await functions[x]();
        await fun();
    }
    
    let arr = new Array();
    while (n--)
        arr.push(fun());
    
    await Promise.all(arr);
    return Promise.all(arr)
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */
