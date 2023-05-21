/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
var areDeeplyEqual = function(o1, o2) {
    if (o1 === o2) return true;
    
     if (typeof o1 !== 'object' || o1 === null ||
         typeof o2 !== 'object' || o2 === null)
         return false;
    
    const a1 = Array.isArray(o1),
          a2 = Array.isArray(o2);
    
    if (a1 !== a2) return false;
    
    if (a1 && a2)
        return o1.length === o2.length &&
                o1.every((v, i) => areDeeplyEqual(v, o2[i]));
    
    const k1 = Object.keys(o1),
          k2 = Object.keys(o2);
    
    if (k1.length !== k2.length) return false;
    
    return k1.every((k) => 
    {
        if (!k2.includes(k)) 
            return false;
        return areDeeplyEqual(o1[k], o2[k]);
    });
};