class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> dp(N, vector<double>(N, 0));
        int dr[] = {2, 2, 1, 1, -1, -1, -2, -2};
        int dc[] = {1, -1, 2, -2, 2, -2, 1, -1};
        
        dp[r][c] = 1;
        for (; K > 0; K--) {
            vector<vector<double>> dp2(N, vector<double>(N, 0));
            for (int row = 0; row < N; row++) {
                for (int col = 0; col < N; col++) {
                    for (int k = 0; k < 8; k++) {
                        int cr = row + dr[k];
                        int cc = col + dc[k];
                        if (0 <= cr && cr < N && 0 <= cc && cc < N) dp2[cr][cc] += dp[row][col]/8.0;
                    }
                }
            }
            dp = dp2;
        }
        double ans = 0.0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) ans += dp[i][j];
        }
        
        return ans;
    }
};
