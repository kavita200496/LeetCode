class Solution {
public:
    double soupServings(int N) {
        N = N/25 + (N%25 > 0 ? 1 : 0);
        if (N >= 500) return 1.0;
        
        double dp[N+1][N+1];
        for (int s = 0; s <= 2*N; s++) {
            for (int i = 0; i <= N; i++) {
                int j = s-i;
                if (j < 0 || j > N) continue;
                double ans = 0.0;
                if (i == 0) ans = 1.0;
                if (i == 0 && j == 0) ans = 0.5;
                if (i > 0 && j > 0) {
                    ans = 0.25 * (dp[max(0,i-4)][j] + dp[max(0, i-3)][max(0, j-1)] +
                                 dp[max(0, i-2)][max(0, j-2)] + dp[max(0, i-1)][max(0, j-3)]);
                }
                dp[i][j] = ans;
            }
        }
         
        return dp[N][N];
    }
};
