/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    Node* solve(vector<vector<int>> &g, int x, int y, int l)
    {
        if (l == 1) return new Node(g[x][y], true);
        
        Node* tl = solve(g, x, y, l / 2);
        Node* tr = solve(g, x, y + l / 2, l / 2);
        Node* bl = solve(g, x + l / 2, y, l / 2);
        Node* br = solve(g, x + l / 2, y + l / 2, l / 2);
    
        if (tl -> isLeaf && tr -> isLeaf && bl -> isLeaf && br -> isLeaf
           && tl -> val == tr -> val && tr -> val == bl -> val && bl -> val == br -> val)
            return new Node(tl -> val, true);
            
        return new Node(false, false, tl, tr, bl, br);
    }
    
public:
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, 0, 0, grid.size());
    }
};