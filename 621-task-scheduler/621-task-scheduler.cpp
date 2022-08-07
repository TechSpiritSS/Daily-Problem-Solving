class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> c(26);
        int maxC = 0;
        
        for (auto &i : tasks)
            ++c[i - 'A'];
        
        for (auto &i : c)
            maxC = max(maxC, i);
        
        --maxC;
        int idle = maxC * n;
        idle += maxC;
        
        for (auto &i : c)
            idle -= min(i, maxC);
        
        return idle > 0 ? idle + tasks.size() : tasks.size();
    }
};