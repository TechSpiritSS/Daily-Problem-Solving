class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        map<int, int> nextGreater;
        
        for (int &i : nums2)
        {
            while (!st.empty() && st.top() < i)
            {
                nextGreater[st.top()] = i;
                st.pop();
            }
            
            st.push(i);
        }
        
        vector<int> ans;
        
        for (int &i : nums1)
            ans.push_back( nextGreater.count(i) ? nextGreater[i] : -1 );
        
        return ans;
    }
};