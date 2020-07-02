class Solution {
public:
    int knightDialer(int N) {
        int MOD = 1e9+7;
        
        vector<vector<int>> dp(N+1, vector<int>(10, 0));
        int rows = dp.size();
        int cols = dp[0].size();
        
        for (int c = 0; c < cols; c++) dp[1][c] = 1;
        
        vector<vector<int>> graph = {{4, 6}, {8, 6}, {7, 9}, {8, 4}, {3, 9, 0}, {}, {1, 0, 7},
                                     {6, 2}, {1, 3}, {4, 2}};
        
        for (int i = 2; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (auto& k : graph[j])
                    dp[i][j] = (dp[i][j] + dp[i-1][k])%MOD;
            }
        }
        int res = 0;
        for (int i = 0; i < cols; i++) 
            res = (res + dp[N][i])%MOD;
        
        return res;
          
    }
};
