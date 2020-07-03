class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for (auto x: nums)
            sum += x;
        
        int m = sum/2;
        if (sum%2 == 1) return false;
        int dp[m+1][n+1];
        for (int i = 0; i <= n; i++) dp[0][i] = true;
        for (int i = 1; i <= m; i++) dp[i][0] = false;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i][j-1];
                if (i >= nums[j-1]) {
                    dp[i][j] = dp[i][j] || dp[i-nums[j-1]][j-1];
                }
            }
        }
        return dp[m][n];
    }
};
