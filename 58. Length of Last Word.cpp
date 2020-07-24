class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        if (n == 0) return 0;
        int i = n-1;
        while (s[i] == ' ') {
            i--;
            if (i < 0) return 0;
        }
        int count = 0;
        while (s[i] != ' ') {
            i--;
            count++;
            if (i < 0) return count;
        }
        return count;
    }
};
