class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        if (r == 0) return 0;
        int c = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[r-1][c-1] == 1) return 0;

        vector<vector<int>> dp(r, vector<int>(c, 0));
        dp[0][0] = 1;
        for (int i = 1; i < r; i++) 
            if (obstacleGrid[i][0] == 0) dp[i][0] = dp[i-1][0];
        
        for (int i = 1; i < c; i++) 
            if (obstacleGrid[0][i] == 0) dp[0][i] = dp[0][i-1];
        
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                if (obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[r-1][c-1];
    }
};
