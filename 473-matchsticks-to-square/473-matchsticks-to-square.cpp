class Solution {
    int sides[4] = {0,0,0,0};
    bool square(vector<int> &m, int i)
    {
        if (i == m.size())
            return (sides[0] == 0 && sides[1] == 0 && sides[2] == 0 && sides[3] == 0);
        
        if (m[i] <= sides[0])
        {
            sides[0] -= m[i];
            if (square(m, i + 1))
                return true;
            sides[0] += m[i];
        }
        
        if (m[i] <= sides[1])
        {
            sides[1] -= m[i];
            if (square(m, i + 1))
                return true;
            sides[1] += m[i];
        }
        
        if (m[i] <= sides[2])
        {
            sides[2] -= m[i];
            if (square(m, i + 1))
                return true;
            sides[2] += m[i];
        }
        
        if (m[i] <= sides[3])
        {
            sides[3] -= m[i];
            if (square(m, i + 1))
                return true;
            sides[3] += m[i];
        }
        
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4)
            return false;
        
        int v = sum / 4;
        for (int i = 0; i < 4; ++i)
            sides[i] = v;
        
        sort(matchsticks.rbegin(), matchsticks.rend());
        return square(matchsticks, 0);
    }
};