class Solution {
public:
    int nthUglyNumber(int n) {
        int ugly[n];
        int i2 = 0, i3 = 0, i5 = 0;
        int next_i2 = 2;
        int next_i3 = 3;
        int next_i5 = 5;
        int next = 1;
        
        ugly[0] = 1;
        for (int i = 1; i < n; i++) {
            next = min(next_i2, min(next_i3, next_i5));
            ugly[i] = next;
            
            if (next == next_i2) {
                i2 = i2+1;
                next_i2 = ugly[i2]*2;
            }
            if (next == next_i3) {
                i3 = i3+1;
                next_i3 = ugly[i3]*3;
            } if (next == next_i5) {
                i5 = i5+1;
                next_i5 = ugly[i5]*5;
            }
        }
        return next;
    }
};
