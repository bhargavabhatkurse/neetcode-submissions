class Solution {
public: //check all submissions
    void islandsAndTreasure(vector<vector<int>>& grid) {
        //mutlisource-bfs 

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q; //(i,j)

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) { //start from all treasure cell (the one which reaches the land first, is the closest)
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            //auto& [row,col] = q.front(); this will return a reference which will lead to dangling pointer once the q.pop()

            auto [row,col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int r = row + dirs[i][0];
                int c = col + dirs[i][1];

                if (r < 0 || r >= m || c < 0 ||
                    c >= n || grid[r][c] != INT_MAX) { //if not int_max means it is alreayd seen by a treasure(which will be the closest)
                    continue;
                }

                grid[r][c] = grid[row][col] + 1; //now this land cell will act like new treasure
                q.push({r, c});
            }
        }
    }
};
