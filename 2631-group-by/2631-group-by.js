/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
    let grp = new Map();
    
    for (let i of this)
    {
        let k = fn(i);
        if (grp[k] === undefined) grp[k] = [];
        grp[k].push(i); 
    }
    return grp;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */