class Solution {
    bool divide(int &i)
    {
        int x = i;
        while (x)
        {
            int n = x % 10;
            if (n == 0 || i % n)
                return false;
            x /= 10;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {   
    vector<int> ans;
        for (int i = left; i <= right; ++i)
            if (divide(i))
                ans.push_back(i);
        return ans;
    }
};