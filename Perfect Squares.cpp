class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int ans = INT_MAX;
            for (int j = 1; j <= i; j++) {
                if (i- j*j >= 0) ans = min(ans, dp[i-j*j]);
                else break;
            }
            dp[i] = 1+ans;
        }
        
        return dp[n];
    }
};
