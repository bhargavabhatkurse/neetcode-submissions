class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0},{0, -1}, {0, 1}};
    vector<vector<int>> dp; //dp[r][c] = longest increasing path starting at (r,c)
    //Not taking prevval because: Eg: Once you're at (2,3), the longest increasing path starting from (2,3) doesn't care where you came from.

    int dfs(vector<vector<int>>& matrix, int r, int c, int prevval) {
        int rows = matrix.size(),col = matrix[0].size();

        if(r < 0 || r >= rows || c < 0 || c >=col || matrix[r][c] <= prevval) return 0;
        
        if(dp[r][c] != -1) return dp[r][c];

        int res = 1; //minimum path is 1
        for(auto d: directions ) {
            res = max(res, 1 + dfs(matrix,r + d[0],c + d[1],matrix[r][c]));
        }
        return dp[r][c] = res;
    }

    int longestIncreasingPath_(vector<vector<int>>& matrix) {
        int row = matrix.size(),col = matrix[0].size();
        int ans = 0; //LIP
        dp.assign(row, vector<int>(col,-1));

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                ans = max(ans, dfs(matrix, r, c, INT_MIN)); //prev is int-min for the starting cell
            }
        }
        return ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) { 
        //Kahn's Algorithm - Because it forms a DAG

        int ROWS = matrix.size(), COLS = matrix[0].size();
        vector<vector<int>> indegree(ROWS, vector<int>(COLS, 0)); //treating cells as nodes

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        //check all valid starting nodes
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                for (auto& d : directions) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr >= 0 && nr < ROWS && nc >= 0 &&
                        nc < COLS && matrix[nr][nc] < matrix[r][c]) {
                        indegree[r][c]++;
                    }
                }
            }
        }

        //print
        for (int r = 0; r < ROWS; ++r) {
            for (int  c = 0; c < COLS; ++c) { 
                    cout<<indegree[r][c]<<" ";
            }
            cout<<endl;
        }

        //push all starting nodes
        queue<pair<int, int>> q;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (indegree[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        int LIS = 0;
        while (!q.empty()) {
            //level order
            //Each BFS layer corresponds to taking one step forward in an increasing path.
            //So, the number of layers processed is exactly the length of the longest increasing path.
            //topological order will give me the longest path
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [r, c] = q.front();
                q.pop();
                for (auto& d : directions) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr >= 0 && nr < ROWS && nc >= 0 &&
                        nc < COLS && matrix[nr][nc] > matrix[r][c]) {
                        indegree[nr][nc]--;
                        if (indegree[nr][nc] == 0) {
                            q.push({nr, nc});
                        }
                    }
                }
            }
            LIS++;
        }
        return LIS;
    }
};
