class Solution {
public:
    double average(vector<int>& salary) {
        double ans = 0.0;
        for (auto &i : salary) 
            ans += i;
        ans -= *min_element(salary.begin(), salary.end());
        ans -= *max_element(salary.begin(), salary.end());
        
        return ans / (salary.size() - 2);
    }
};