class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> umap;
        
        for (auto i : nums) umap[i]++;
        for (auto i : umap) {
            if (i.second == 2) res.push_back(i.first);
        }
        return res;
    }
};
