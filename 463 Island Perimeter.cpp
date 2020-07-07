class Solution {
public:
    int count(vector<vector<int>> &grid, int i, int j, int r, int c) {
        int peri = 0;
        if (i-1 < 0)peri++;
        else if (grid[i-1][j] == 0) peri++;
        if (i+1 >= r) peri++;
        else if (grid[i+1][j] == 0) peri++;
        if (j-1 < 0) peri++;
        else if (grid[i][j-1] == 0) peri++;
        if (j+1 >= c) peri++;
        else if (grid[i][j+1] == 0) peri++;
        
        return peri;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        if (!r) return 0;
        int c = grid[0].size();
        int ans = 0;
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1)
                    ans += count(grid, i, j, r, c);
            }
        }
        return ans;
    }
};
