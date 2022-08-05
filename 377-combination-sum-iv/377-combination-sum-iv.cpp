class Solution {
    vector<int> v;
    
    int solve(vector<int> &nums, int target){
        if (target == 0) 
            return 1;
        
        if (target < 0) 
            return 0;
        
        if (v[target] != -1) 
            return v[target];
        
        int ans = 0;
        
        for (auto &it : nums) 
            ans += solve(nums, target - it);
        
        return v[target] =  ans;
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        v.resize(target + 1, -1);
        return solve(nums, target);
    }
};