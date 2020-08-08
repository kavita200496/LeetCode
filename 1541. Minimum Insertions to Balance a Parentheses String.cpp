class Solution {
public:
    int minInsertions(string s) {
       int l = 0, r = 0, res = 0;
       for (auto ch : s) {
         if (ch == '(') {
            if (r != 0) {
                res += l > 0 ? 1 : 2;
                l = max(0, l - 1);
                r = 0;
            }
            ++l;
        } else if (++r == 2) {
            r = 0;
            if (l > 0)
                --l;
            else
                ++res;
        }
    }
    if (l > 0)
        return res + 2 * l - r;
    return res + (r == 1 ? 2 : 0);
    }
};
