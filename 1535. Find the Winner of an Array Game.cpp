class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxi = *max_element(arr.begin(), arr.end());
        int n = arr.size();
        if (k >= n) return maxi;
        int p1 = 0, p2 = 1, c = 0;
        vector<int> tmp(maxi+1, 0);
        
        while (c < n) {
            if (arr[p1] == maxi || arr[p2] == maxi) return maxi;
            if (arr[p1] > arr[p2]) {
                tmp[arr[p1]]++;
                if (tmp[arr[p1]] >= k) return arr[p1];
                p2++;
            } else {
                tmp[arr[p2]]++;
                if (tmp[arr[p2]] >= k) return arr[p2];
                p1 = p2;
                p2++;
            }
            c++;
         }
        return maxi;
    }
};
