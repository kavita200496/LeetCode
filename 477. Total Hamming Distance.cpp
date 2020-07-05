class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
       ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        
        int n = nums.size();
        int ans = 0;
        int a[32] = {0};
        for(int i = 0; i<n ; i++)
            for(int j = 0; j<32; j++) 
                a[j] += (nums[i] & (1 << j))!=0;
            
        for(int i = 0; i<32; i++)ans += (a[i])*(n-a[i]);
        return ans;
    }
};
