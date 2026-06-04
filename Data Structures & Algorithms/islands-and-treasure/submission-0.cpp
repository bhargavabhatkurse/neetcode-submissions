class Solution {
    int row,col;
    vector<vector<int>> directions = {{1, 0}, {-1, 0},
                                      {0, 1}, {0, -1}};
    
    int INF = INT_MAX;

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == INF) {
                    grid[r][c] = bfs(grid, r, c);
                }
            }
        }
    }

    int bfs(vector<vector<int>>& grid, int r, int c) {
        queue<pair<int, int>> q;
        q.push({r, c});
        
        vector<vector<bool>> visit(row, vector<bool>(col, false));
        
        visit[r][c] = true;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) { //level wise processing
                auto [r, c] = q.front();
                q.pop();
                
                if (grid[r][c] == 0) return steps;
                
                for (auto& dir : directions) {
                    int nr = r + dir[0], nc = c + dir[1];
                    if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                        !visit[nr][nc] && grid[nr][nc] != -1) {
                        
                        visit[nr][nc] = true;
                        q.push({nr, nc});

                    }
                }
            }
            
            steps++;
        }

        return INF;
    }

};
