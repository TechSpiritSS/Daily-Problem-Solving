class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        
        for (auto &i : asteroids)
        {
            if (i > 0)
            {
                st.push_back(i);
                continue;
            }
            
            while (st.size() && st.back() > 0 && st.back() < -i)
                st.pop_back();
            
            if (st.size() && st.back() + i == 0)
                st.pop_back();
            
            else if (st.empty() || st.back() < 0) 
                st.push_back(i);
        }
        
        return st;
    }
};