class Solution {
public:
    vector<vector<int>> dp; 
    int rec(vector<vector<int>>& grid,int i, int j) {
        if(i == grid.size()-1 && j == grid[0].size()-1) return grid[i][j];
        if(i >= grid.size() || j >= grid[0].size()) return 1e9; //not possible
        if(dp[i][j] != -1) return dp[i][j];
        int curr_cost = min(rec(grid,i+1,j),rec(grid,i,j+1)) + grid[i][j];
        
        return dp[i][j] = curr_cost; 

    }

     int minPathSum_topdown(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        dp.assign(n,vector<int>(m,-1));
        return rec(grid,0,0);
     }

    int minPathSum_bottomUp(vector<vector<int>>& grid) {
        // int n = grid.size(),m = grid[0].size();
        // dp.assign(n,vector<int>(m,-1));
        // return rec(grid,0,0);


        //bottom up: 
        int n = grid.size(),m = grid[0].size();
        dp.assign(n+1,vector<int>(m+1,1e9));

        for(int i = n-1; i>=0; i--)
        for(int j = m-1; j>=0;j--) {
        if(i == n-1 && j == m-1) dp[i][j] = grid[i][j]; //goal case
        else
        dp[i][j] = min(dp[i+1][j],dp[i][j+1]) + grid[i][j];
        }
        return dp[0][0];
    }

     int minPathSum(vector<vector<int>>& grid) {
        //space optimised
        int n = grid.size(),m = grid[0].size();
        vector<int> dpnext(m+1,1e9);
        vector<int> dp(m+1,1e9);


        for(int i = n-1; i>=0; i--)
        for(int j = m-1; j>=0;j--) {
        if(i == n-1 && j == m-1) dp[j] = grid[i][j]; //goal case
        else
        dp[j] = min(dpnext[j],dp[j+1]) + grid[i][j];
        dpnext = dp;
        }
        return dp[0];
     }
};