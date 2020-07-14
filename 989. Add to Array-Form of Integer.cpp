class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int n = A.size();
        int carry = 0;
        int i = n-1;
        
        while (i >= 0 || K) {
            if (i < 0) {
                A.insert(A.begin(), K%10+carry);
                if (A[0] > 9) {
                    A[0] = A[0]%10;
                    carry = 1;
                } else carry = 0;
            } else {
                A[i] = A[i]+K%10 + carry;
                if (A[i] > 9) {
                    A[i] %= 10;
                    carry = 1;
                } else carry = 0;
            }
            K = K/10;
            i--;
        }
        if (carry == 1) A.insert(A.begin(), 1);
        return A;
    }
};
