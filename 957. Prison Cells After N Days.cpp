class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> tmp(8);
        vector<vector<int>> seen;
        
        while (N--) {
            for (int i = 1; i < 7; i++) {
                tmp[i] = cells[i-1] == cells[i+1];
            }
                if (seen.size() && seen.front() == tmp) return seen[N%seen.size()];
                else seen.push_back(tmp);
                cells = tmp;
            }
        return cells;
        }
};
