class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        string one, two,s;
        
        istringstream iss(text);
        
        while (iss >> s) {
            if (one.empty()) one = s;
            else if (two.empty()) two = s;
            else {
                if (one == first && second == two) {
                    res.push_back(s);
                }
                one = two;
                two = s;
            }
        }
        return res;
    }
};
