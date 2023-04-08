/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> graphs;
    
public:
    Node* cloneGraph(Node* node) { 
        if (!node) return NULL;
        
        if (graphs.find(node) == graphs.end())
        {
            graphs[node] = new Node(node -> val, {});
            
            for (auto &i : node -> neighbors)
                graphs[node] -> neighbors.push_back(cloneGraph(i));
        }
  
        return graphs[node];
    }
};