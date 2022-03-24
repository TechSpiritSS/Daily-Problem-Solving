class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int ans = 0;
        
        for (int i = people.size() - 1, j = 0; i >= j; --i)
        {
            if (i == j)
                ans += 1;
            
            else if (people[i] + people[j] <= limit)
            {
                ans += 1;
                ++j;
            }
            
            else
                ans += 1;
        }
        
        return ans;
    }
};