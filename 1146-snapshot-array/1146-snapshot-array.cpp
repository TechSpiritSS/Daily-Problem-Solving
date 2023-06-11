class SnapshotArray {
    int snapId;
    vector<vector<pair<int, int>>> history;
    
public:
    SnapshotArray(int length) {
        snapId = 0;
        history.resize(length);
        
        for (auto &i : history)
            i.push_back({0, 0});
    }
    
    void set(int index, int val) {
        history[index].push_back({snapId, val});
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto i = upper_bound(history[index].begin(), history[index].end(), make_pair(snap_id, INT_MAX));
        return prev(i) -> second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */