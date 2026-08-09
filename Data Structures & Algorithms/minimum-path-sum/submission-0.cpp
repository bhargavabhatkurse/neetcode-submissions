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
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        dp.assign(n,vector<int>(m,-1));
        return rec(grid,0,0);
    }
};