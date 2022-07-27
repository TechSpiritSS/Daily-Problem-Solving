class Solution {
    
    void dfs(vector<vector<int>> &img, int i, int j, int c, int oc)
    {
        if (img[i][j] != oc || img[i][j] == c) return;
        
        img[i][j] = c;
        
        if (i > 0) dfs(img, i - 1, j, c, oc);
        if (j > 0) dfs(img, i, j - 1, c, oc);
        if (i + 1 < img.size()) dfs(img, i + 1, j, c, oc);
        if (j + 1 < img[i].size()) dfs(img, i, j + 1, c, oc);
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};