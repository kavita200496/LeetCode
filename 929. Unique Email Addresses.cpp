class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int n = emails.size();
        
        unordered_map<string, set<string>> umap;
        
        for (int i = 0; i < n; i++) {
            int j = 0;
            int flag = 0;
            while (emails[i][j] != '@') {
                if (emails[i][j] == '.') emails[i].erase(emails[i].begin()+j);
                else if (emails[i][j] == '+') {
                    flag = 1;
                    emails[i].erase(emails[i].begin()+j);
                } else if (flag == 1) emails[i].erase(emails[i].begin()+j);
                else j++;
            }
            string t1 = emails[i].substr(0, j);
            string t2 = emails[i].substr(j, emails[i].size());
            umap[t1].insert(t2);
        }
        int count = 0;
        for (auto i : umap) {
            count += i.second.size();
        }
        return count;
    }
};
