class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }
        if (fresh == 0) return 0;
        int min = 0;
        
        vector<vector<int>> v = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int n = q.size();
            min++;
            while (n--) {
                auto [i, j] = q.front();
                q.pop();
                for (auto& d : v) {
                    int x = d[0]+i;
                    int y = d[1]+j;
                    if (x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push({x,y});
                        fresh--;
                    }
                }
               
            }
             if (fresh <= 0) break;
        }
        return (fresh > 0) ?-1:min;
    }
};
