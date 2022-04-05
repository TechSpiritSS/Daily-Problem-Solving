class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int maxArea = 0;
        int minH = height[0];
        
        while (start <= end)
        {
            minH = min(height[start], height[end]);
            maxArea = max(maxArea, minH * (end - start));
            
            if (height[start] < height[end])
                ++start;
            else
                --end;
        }
        
        return maxArea;
    }
};