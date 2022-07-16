class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector< pair<int, int>> cars;
        for (int i = 0; i < speed.size(); ++i)
            cars.push_back({position[i], speed[i]});
        
        sort(cars.rbegin(), cars.rend());
        
        float currTime = INT_MIN;
        int count = 0;
        
        for (auto &i : cars)
        {
            float time = (target - i.first) / (1.0 * i.second);
            if (currTime < time)
                ++count;
            currTime = max(time, currTime);
        }
        return count;
    }
};