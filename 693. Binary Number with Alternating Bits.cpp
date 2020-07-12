class Solution {
public:
    bool hasAlternatingBits(int n) {
        int tmp = n%2;
        n = n/2;
        while (n) {
            if (tmp == n%2) return false;
            tmp = n%2;
            n = n/2;
        }
        return true;
    }
};
