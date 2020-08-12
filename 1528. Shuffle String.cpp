class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        char res[s.size()];
        int j = 0;
        for (auto i : indices) {
            res[i] = s[j++];
        }
        string r = "";
        for (auto i : res) {
            r += i;
        }
        return r;
    }
};
