/**
 * @param {number[]} edges
 * @param {number} node1
 * @param {number} node2
 * @return {number}
 */

var closestMeetingNode = function(edges, node1, node2) {
    let s = edges.length;
    let d1 = new Array(s).fill(-1);
    let d2 = new Array(s).fill(-1);
    
    const dfs = (e, n, d) => {
        let dis = 0;
        for (let i = n; i !== -1 && d[i] === -1; i = e[i])
            d[i] = dis++;
    }
    
    dfs(edges, node1, d1);
    dfs(edges, node2, d2);
    
    let min_d = 1000000;
    let ans = -1;
    
    for (let i = 0; i < s; ++i)
        if (Math.min(d1[i], d2[i]) >= 0 && Math.max(d1[i], d2[i]) < min_d)
        {
            ans = i;
            min_d = Math.max(d1[i], d2[i]);
        }
    
    return ans;
};