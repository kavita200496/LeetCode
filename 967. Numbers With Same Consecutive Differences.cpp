class Solution {
public:
    void dfs(int n, int num, int K, vector<int>& res) {
        if (n == 0) {
            res.push_back(num);
            return;
        }
        
        vector<int> tmp;
        int tail = num%10;
        tmp.push_back(tail+K);
        if (K != 0) tmp.push_back(tail-K);
        for (int nextDigit : tmp) {
            if (nextDigit >= 0 && nextDigit < 10) {
                int newn = num*10 + nextDigit;
                dfs(n-1, newn, K, res);
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 1) return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> res;
        
        for (int i = 1; i < 10; i++) {
            dfs(N-1, i, K, res);
        }
        return res;
    }
};
