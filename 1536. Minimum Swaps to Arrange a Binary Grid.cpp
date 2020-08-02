class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> t;
        int n = grid.size();
        
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n; --j >= 0 && !grid[i][j]; ) count++;
            t.push_back(count);
        }
        
        int ans = 0;
        for (int i = 0; i < t.size(); i++) {
            int k = i;
            int req = n-1-i;
            
            while (k < n && t[k] < req) k++;
            if (k == n) return -1;
            ans += k-i;
            
            while (k > i) {
                t[k] = t[k-1];
                k--;
            }
        }
        return ans;
    }
};
