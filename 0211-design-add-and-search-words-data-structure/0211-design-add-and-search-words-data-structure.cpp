class Trie {
public:
    bool isLeaf;
    Trie* child[26];
    
    Trie() {
        isLeaf = false;
        memset(child, 0, sizeof(child));
    }  
};

class WordDictionary {    
    Trie* root = NULL;;

    bool search2(string word, Trie* r)
    {
        for (int i = 0; i < word.length(); ++i)
        {
            if (word[i] == '.')
            {
                for (auto &c : r->child)
                    if (c && search2(word.substr(i + 1), c)) 
                        return true;
                
                return false;
            } 
            
            int idx = word[i] - 'a';
            
            if (!r->child[idx])
                return false;
            
            r = r->child[idx];
        }
        return r->isLeaf;
    }
    
public:
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* r = root;
        
        for (auto &i : word)
        {
            int idx = i - 'a';
            
            if (!r->child[idx])
                r->child[idx] = new Trie();
            
            r = r->child[idx];
        }
        
        r->isLeaf = true;
    }
    
    bool search(string word) {        
        return search2(word, root);
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */