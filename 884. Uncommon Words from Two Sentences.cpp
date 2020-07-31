class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> res;
        string s;
        unordered_map<string, int> umap;
        stringstream a(A);
        
        while(a >> s) umap[s]++;
        
        stringstream b(B);
        while (b >> s) umap[s]++;
        
        for (auto i : umap) {
            if(i.second == 1) res.push_back(i.first);
        }
        return res;
    }
};
