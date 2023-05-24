/**
 * @param {object} obj1
 * @param {object} obj2
 * @return {object}
 */
function objDiff(obj1, obj2) {
    if (obj1 === obj2) return {};
    if ((!obj1 || !obj2) ||
       (typeof obj1 !== 'object' || typeof obj2 !== 'object') ||
       (Array.isArray(obj1) !== Array.isArray(obj2)))
        return [obj1, obj2];
    
    const x = {};
    
    for (const key in obj1)
        if (key in obj2)
        {
            const diff = objDiff(obj1[key], obj2[key]);
            if (Object.keys(diff).length)
                x[key] = diff;
        }
    
    return x;
};