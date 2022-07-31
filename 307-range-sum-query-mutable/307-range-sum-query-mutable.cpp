class NumArray {
public:
    vector<int> v;
    int sum;  
    NumArray(vector<int>& nums) {
        v = nums;
        sum = 0;
        for (auto &i : nums)
            sum += i;
    }
    
    void update(int index, int val) {
        sum -= v[index];    
        v[index] = val;
        sum += val;
        
    }
    
    int sumRange(int left, int right) {
        int res;
        
        if (right - left < v.size() / 2)
            res = accumulate(v.begin() + left, v.begin() + right + 1, 0);
        
        else
            res = sum - accumulate(v.begin(), v.begin() + left, 0) - accumulate(v.begin() + right + 1, v.end(), 0);
        
        return res;
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
