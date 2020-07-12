class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> ans;
        int n = A.size();
        
        if (n <= 1) return n;
        for (int i = 0; i < n; i++) {
             int j = i-1;
            int x = 0, y = A[i];
            ans.insert(y);
            while (j >= 0 && x != y) {
                x |= A[j];
                y |= A[j];
                ans.insert(y);
                j--;
            }
        }
        return ans.size();
    }
};
