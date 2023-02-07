class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int l = 0, ans = 0;
        
        for (int i = 0; i < fruits.size(); ++i)
        {
            ++basket[fruits[i]]; 
            while (basket.size() > 2)
            {
                --basket[fruits[l]];
                if (basket[fruits[l]] == 0) basket.erase(fruits[l]);
                ++l;
            }    
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};