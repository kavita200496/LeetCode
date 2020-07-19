class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        unordered_map<int, pair<int, int>> m;
        vector<vector<int>> mappings(board.size(), vector<int>(board.size(), 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int index = (i*n+j)+1;
                if (!(i&1)) {
                    m[index] = {n-i-1, j};
                    mappings[n-i-1][j] = index;
                } else {
                    m[index] = {n-i-1, n-j-1};
                    mappings[n-i-1][n-j-1] = index;
                }
            }
        }
        
        queue<pair<int, int>> q;
        unordered_set<int> visited;
        visited.insert(mappings[n-1][0]);
        q.push({n-1, 0});
        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto p = q.front();
                q.pop();
                int i = p.first, j = p.second;
                
                if (board[i][j] != -1) {
                    auto t = m[board[i][j]];
                    i = t.first, j = t.second;
                }
                int curr = mappings[i][j];
                if (curr == n*n) return dist;
                for (int k = curr+1; k <= curr+6 && k <= n*n; k++) {
                    if (!visited.count(k)) {
                        q.push(m[k]);
                        visited.insert(k);
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};
