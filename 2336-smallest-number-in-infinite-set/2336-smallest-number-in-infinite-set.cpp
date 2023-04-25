class SmallestInfiniteSet {
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> s;
    int cur;

public:
    SmallestInfiniteSet() {
        cur = 1;
    }

    int popSmallest() {
        int ans;
        
        if (!pq.empty()) 
        {
            ans = pq.top();
            s.erase(ans);
            pq.pop();
        } 
        else 
        {
            ans = cur;
            ++cur;
        }
        
        return ans;
    }

    void addBack(int num) {
        if (cur <= num || s.find(num) != s.end())
            return;
        
        pq.push(num);
        s.insert(num);
    }
};
/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */