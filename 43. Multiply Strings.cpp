class Solution {
public:
    string multiply(string num1, string num2) {
        string res(num1.length()+num2.length(), '0');
        
        for (int i = num1.size()-1; i >= 0; i--) {
            for (int j = num2.size()-1; j >= 0; j--) {
                int sum = (num1[i]-'0')*(num2[j]-'0')+(res[i+j+1]-'0');
                res[i+j+1] = sum%10+'0';
                res[i+j] += sum/10;
            }
        }
        
        for (int i = 0; i < res.size(); i++) {
            if (res[i] != '0') return res.substr(i);
        }
        return "0";
    }
};
