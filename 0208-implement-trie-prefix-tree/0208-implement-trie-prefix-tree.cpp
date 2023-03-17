class Trie {
    struct TrieNode {
        TrieNode* child[26];
        bool isLeaf;
    };
    
    TrieNode *root = NULL;
    
    TrieNode* getNode()
    {
        TrieNode* node = new TrieNode();
        
        for (int i = 0; i < 26; ++i)
            node -> child[i] = NULL;
        
        node -> isLeaf = false;
        return node;
    }
    
public:
    Trie() {}
    
    void insert(string word) {
        if (search(word)) return;
        if (!root) root = getNode();
        
        TrieNode *node = root;
        
        for (auto &i : word)
        {
            int idx = i - 'a';
            
            if (!node -> child[idx])
                node -> child[idx] = getNode();
        
            node = node -> child[idx];
        }
        node -> isLeaf = true;
    }
    
    bool search(string word) {
        if (!root) return false;
        
        TrieNode *node = root;
        
        for (int i = 0; i < word.length() && node; ++i)
        {
            int idx = word[i] - 'a';
            node = node -> child[idx];
        }
        
        if (node) return node -> isLeaf;
        return false;
    }
    
    bool startsWith(string prefix) {
        if (!root) return false;
        
        TrieNode *node = root;
        
        for (int i = 0; i < prefix.length() && node; ++i)
        {
            int idx = prefix[i] - 'a';
            node = node -> child[idx];
        }
        
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */