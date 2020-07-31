class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> umap;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            umap[nums[i]]++;
        }
        
        for (auto i : umap) {
           
            if (i.second <= 2) count += i.second-1;
            else count += i.second*(i.second-1)/2;
        }
        return count;
    }
};
