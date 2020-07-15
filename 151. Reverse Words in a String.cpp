class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        if (n == 0) return s;
        
        int i = 0;
        while (s[i] == ' ') i++;
        for (i; i < n; i++) {
            int j = i;
            while (s[j] != ' ' && s[j] != '\0') {
                j++;
            }
            reverse(s.begin()+i, s.begin()+j);
            i = j;
        }
        reverse(s.begin(), s.end());
        i = 0;
        int j = n-1;
        while (s[i] == ' ' && i < n) i++;
        while (s[j] == ' ' && j >= 0 && j > i)j--;
        
        string res(s.begin()+i, s.begin()+j+1);
        for (int k = 0; k < res.size(); k++) {
            if (res[k] == ' ') {
                while (res[k+1] == ' ') res.erase(res.begin()+k);
            }
        }
        return res;
    }
};
