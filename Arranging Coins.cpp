class Solution {
public:
    int arrangeCoins(int n) {
        if (n < 2) return n;
        
        n = n-1;
        int i = 2;
        for (i; i <= n; i++) {
            n = n-i;
        }
        
        return i-1;
    }
};
