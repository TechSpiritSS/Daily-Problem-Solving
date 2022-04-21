class MyHashSet {
    int n[1000001] {0};
public:
    MyHashSet() {
    }
    
    void add(int key) {
        n[key] = 1;
    }
    
    void remove(int key) {
        n[key] = 0;
    }
    
    bool contains(int key) {
        return n[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */