class Solution {
public:
    void dfs(string src, vector<string>& res, unordered_map<string, vector<string>>& ump) {
        while (!ump[src].empty()) {
            string s = ump[src].back();
            ump[src].pop_back();
            dfs(s, res, ump);
        }    
        res.push_back(src);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        unordered_map<string, vector<string>> ump;
        
        for (auto i : tickets) ump[i[0]].push_back(i[1]);
        
        for (auto& i : ump) sort(i.second.begin(), i.second.end(), greater<string>());
        
        dfs("JFK", res, ump);
        reverse(res.begin(), res.end());
        return res;
    }
};
