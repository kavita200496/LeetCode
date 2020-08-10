class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        int n = s.length()-1;
        int i = n;
        while(i>=0)
        {
            result = result + (pow(26,(n-i))*(s[i]-'A'+1));
            i--;
        }
        
        return result;
    }
};
