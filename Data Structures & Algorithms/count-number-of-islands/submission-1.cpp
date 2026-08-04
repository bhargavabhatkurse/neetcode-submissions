class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        int islands = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == '1') {
                    //dfs(grid, r, c);
                    bfs(grid,r,c);
                    islands++;
                }
            }
        }

        return islands;
    }

    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() ||
            c >= grid[0].size() || grid[r][c] == '0') {
            return;
        }

        grid[r][c] = '0';
        for (int i = 0; i < 4; i++) {
            dfs(grid, r + directions[i][0], c + directions[i][1]);
        }
    }


    void bfs(vector<vector<char>>& grid, int r, int c) {
        queue<pair<int,int>> q;

        grid[r][c] = '0';
        q.push({r, c});

        while(!q.empty()) {
            auto node = q.front(); q.pop();
            int row = node.first, col = node.second;

            for(auto dir: directions) {
                int nr = row + dir[0];
                int nc = col + dir[1];

                //check if valid
                if(nr >=0 && nc >=0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == '1') {
                    q.push({nr,nc});

                    //mark as visited
                    grid[nr][nc] = '0';
                }
            }
        }


    }
};