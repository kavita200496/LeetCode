class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int n = words.size();
        vector<string> res;
        unordered_map<char, int> umap {
        {'z',1},{'x',1},{'c',1},{'v',1},{'b',1},{'n',1},{'m',1},
        {'a',2},{'s',2},{'d',2},{'f',2},{'g',2},{'h',2},{'j',2},{'k',2},{'l',2},
        {'q',3},{'w',3},{'e',3},{'r',3},{'t',3},{'y',3},{'u',3},{'i',3},{'o',3},{'p',3}};
        
        set<int> mySet;
        char tmp;
        
        for (auto i : words) {
            for (auto c : i) {
                tmp = tolower(c);
                mySet.insert(umap[tmp]);
                if (mySet.size() > 1) break;
            }
            if (mySet.size() == 1) res.push_back(i);
            mySet.clear();
        }
        return res;
    }
};
