class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        int n = stations.size();
        int currFuel = startFuel, i = 0;
        int res = 0;

        priority_queue<int> pq;

        while (currFuel < target)
        {

            while (i < n && currFuel >= stations[i][0])
            {
                pq.push(stations[i][1]);
                i++;
            }

            if (pq.empty())
                return -1;

            currFuel += pq.top();
            pq.pop();

            res++;
        }
        return res;
    }
};