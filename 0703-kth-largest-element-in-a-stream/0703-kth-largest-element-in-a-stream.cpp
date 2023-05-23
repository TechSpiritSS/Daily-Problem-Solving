class KthLargest {
    int x;
    vector<int> n;
public:
    KthLargest(int k, vector<int>& nums) {
        x = k;
        sort(nums.begin(), nums.end());
        n = nums;
    }
    
    int add(int val) {
        int i;
        for (i = 0; i < n.size(); ++i)
            if (val <= n[i])
            {
                n.insert(n.begin() + i,val);
                break;
            }
        
        if (i == n.size())
            n.insert(n.begin() + i, val);
        
        return n[n.size() - x]; 
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */