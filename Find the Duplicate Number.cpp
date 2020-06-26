class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        for (int i = 0; i < n; i++) {
            if (nums[abs(nums[i])] < 0) return abs(nums[i]);
            nums[abs(nums[i])] = -nums[abs(nums[i])];
        }
        for(int i = 0; i < nums.size(); i++){
            nums[i] = abs(nums[i]);
        }
        return 0;
    }
};
