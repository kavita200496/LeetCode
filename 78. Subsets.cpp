class Solution {
public:
    vector<int> findsubsets(int n, vector<int> nums) {
        vector<int> tmp;
        int i = 0;
        while (n) {
            if (n & 1) {
                tmp.push_back(nums[i]);
            }
            i++;
            n >>= 1;
        }
        return tmp;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total = 1 << n;
        vector<vector<int>> res;
        
        for (int i = 0; i < total; i++) {
            vector<int> tmp = findsubsets(i, nums);
            res.push_back(tmp);
        }
        return res;
    }
};
