class Solution {
    int binarySearch(vector<int>& numbers, int n, int i)
    {
        int s = i;
        int e = numbers.size() - 1;
        
        while(s <= e)
        {
            int m = (s + e) / 2;
            if (numbers[m] == n)
                return m;
            if (numbers[m] > n)
                e = m - 1;
            if (numbers[m] < n)
                s = m + 1;
        }
        return -1;
    }
    
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s = numbers.size();
        vector<int> ans;
        
        for(int i = 0; i < s; ++i)
        {
            int x = binarySearch(numbers, target - numbers[i], i + 1);
                if (x == -1)
                    continue;
                else
                {
                    ans.push_back(i + 1);
                    ans.push_back(x + 1);
                    break;
                }
        }
        return ans;
    }
};