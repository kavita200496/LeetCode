class Solution {
public:
    bool search (vector<int> g, int row, vector<int>& nums, int target) {
        if (row < 0) return true;
        int v = nums[row--];
        for (int i = 0; i < g.size(); i++) {
            if (g[i]+v <= target) {
                g[i] += v;
                if (search(g, row, nums, target)) return true;
                g[i] -= v;
            }
            if(g[i] == 0) break;
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (auto i : nums) sum += i;
        if (sum%k > 0) return false;
        int target = sum/k;
        
        sort(nums.begin(), nums.end());
        int r = nums.size()-1;
        if (nums[r] > target) return false;
        
        while (r >= 0 && nums[r] == target) {
            r--; k--;
        }
        vector<int> v(k);
        return search(v, r, nums, target);
    }
};
