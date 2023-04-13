class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(), i = 0;
        stack<int> st;
        
        for (int &x : pushed)
        {
            st.push(x);
            while (!st.empty() && i < n && st.top() == popped[i])
            {
                st.pop();
                ++i;
            }
        }
        
        return i == n;
    }
};