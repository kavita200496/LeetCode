class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10) return {};
        unordered_set<string> tmp;
        unordered_set<string> res;
        
        for (int i = 0; i <= s.length()-10; i++) {
            if (tmp.count({s.data()+i, 10})) {
                res.insert(s.substr(i, 10));
            }
            else {
                tmp.insert({s.data()+i, 10});
            }
        }
        for (auto i : res)cout<<i<<endl;
        return {res.begin(), res.end()};
    }
};
