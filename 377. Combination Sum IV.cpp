class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<int> dp(target+1, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] <= target) dp[nums[i]] = 1;
        }
        
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < n; j++) {
                if (nums[j] >= i) continue;
                if (dp[i-nums[j]] < (INT_MAX - dp[i]))
                    dp[i] +=  dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};
