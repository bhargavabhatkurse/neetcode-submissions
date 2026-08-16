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

    int longestIncreasingPath(vector<vector<int>>& matrix) {
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
};
