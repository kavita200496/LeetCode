class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int N = nums.size();
        if (N <= 1) return N;
        vector<int> lengths(N, 1);
        vector<int> counts(N, 1);
    
         for (int j = 0; j < N; ++j) {
            for (int i = 0; i < j; ++i) if (nums[i] < nums[j]) {
                if (lengths[i] >= lengths[j]) {
                    lengths[j] = lengths[i] + 1;
                    counts[j] = counts[i];
                } else if (lengths[i] + 1 == lengths[j]) {
                    counts[j] += counts[i];
                }
            }
        }
        
        int longest = 0, ans = 0;
        for (int length: lengths) {
            longest = max(longest, length);
        }
        for (int i = 0; i < N; ++i) {
            if (lengths[i] == longest) {
                ans += counts[i];
            }
        }
        return ans;
        
    }
};
