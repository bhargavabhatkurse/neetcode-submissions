class Solution {
    int row,col;
    vector<vector<int>> directions = {{1, 0}, {-1, 0},
                                      {0, 1}, {0, -1}};
    
    int INF = INT_MAX;

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        //o(m*n * (m*n)) = o(m*n)^2    (bfs complexity in a grid is R*C (r*c vertices))
        row = grid.size();
        col = grid[0].size();

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == INF) { //for each land cell
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
                
                //visit[r][c] = true; //better to make it visited while entering
                
                if (grid[r][c] == 0) return steps;
                
                for (auto& dir : directions) {
                    int nr = r + dir[0], nc = c + dir[1];
                    if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                        !visit[nr][nc] && grid[nr][nc] != -1) { //check bounds first and then the visit array and grid
                        
                        visit[nr][nc] = true; //making visited here is optimal
                        q.push({nr, nc});

                    }
                }
            }
            
            steps++;
        }

        return INF;
    }
// Input: [
//   [2147483647,-1,0,2147483647],
//   [2147483647,2147483647,2147483647,-1],
//   [2147483647,-1,2147483647,-1],
//   [0,-1,2147483647,2147483647]
// ]

// Output: [
//   [3,-1,0,1],
//   [2,2,1,-1],
//   [1,-1,2,-1],
//   [0,-1,3,4]
// ]
};
