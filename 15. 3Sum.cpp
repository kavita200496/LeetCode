class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> triplets;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
      if (i != 0 && nums[i] == nums[i - 1]) continue;
      int need = -nums[i];
      int l = i + 1, r = n - 1;
      while (l < r) {
        if (nums[l] + nums[r] == need) {
          triplets.push_back({nums[i], nums[l], nums[r]});
          r--;
          while (r > l && nums[r] == nums[r + 1]) r--;
        } else if (nums[l] + nums[r] < need) {
          l++;
        } else {
          r--;
        }
      }
    }
    return triplets;
  }
};
