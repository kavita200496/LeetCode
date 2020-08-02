class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0, k = 0;
        long a = 0, b = 0, res = 0;
        
        while (i < n || j < m) {
            if (i < n && (j ==m || nums1[i] < nums2[j])) a += nums1[i++];
            else if (j < m && (i == n || nums2[j] < nums1[i])) b += nums2[j++];
            else {
                res += max(a, b) + nums1[i];
                a = 0, b = 0;
                i++; j++;
            }
        }
        res = (res + max(a, b))%1000000007;
        return res;
    }
};
