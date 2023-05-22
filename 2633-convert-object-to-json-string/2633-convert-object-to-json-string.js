/**
 * @param {any} object
 * @return {string}
 */
var jsonStringify = function(object) {
    if (object === null) return 'null';
    
    if (typeof object === 'string')
        return '"' + object + '"';
    
    if (typeof object === 'number' ||
        typeof object === 'boolean')
        return String(object);
    
    if (Array.isArray(object))
    {
        const x = object.map(i => jsonStringify(i)).join(',');
        return '[' + x + ']';
    }
    
    if (typeof object === 'object')
    {
        const k = Object.keys(object);
        const i = k.map(k => '"' + k + '":' + jsonStringify(object[k]));
        return '{' + i.join(',') + '}';
    }
};