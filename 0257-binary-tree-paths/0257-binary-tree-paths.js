/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {string[]}
 */
var binaryTreePaths = function(root) {
    let ans = [];
    const dfs = (r, s) => 
    {
        if (!root) return;
        if (r.left === null && r.right === null) 
        {
            ans.push(s + r.val);
            return;
        }
        
        if (r.left) dfs(r.left, s + r.val + "->");
        if (r.right) dfs(r.right, s + r.val + "->");
    };
    
    dfs(root, "");
    return ans;
}