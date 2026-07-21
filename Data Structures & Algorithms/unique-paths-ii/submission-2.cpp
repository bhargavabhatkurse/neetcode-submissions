class Solution {
public:
   int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //bottom up:
        int m = obstacleGrid.size(),n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        //edge case
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }

        dp[m-1][n-1] = 1;
        //dp[i][j] = dp[i+1][j] + dp[i][j+1]
        //we know we have to go backward because we need future states to calculate previous

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                 if(i == m-1 && j == n-1) //to avoid recalcutig the base case; although since dp is init with 0, it will be 0+0 so it doesnt matter
                        continue;
                if (obstacleGrid[i][j] == 1) // wall
                    dp[i][j] = 0;
                else
                {
                    dp[i][j] += dp[i + 1][j] + dp[i][j + 1];
                }  
            } 
        }

        return dp[0][0];
    }
    
    vector<vector<int>> dp;
    int rec(vector<vector<int>>& obstacleGrid,int i, int j, int m, int n) {
        if(i == m-1 && j == n-1) return 1; //goal

        if(i >=m || j >=n  || obstacleGrid[i][j] == 1) return 0;

        if(dp[i][j] != -1) return dp[i][j]; //always put dp after checking bounds
        int side = rec(obstacleGrid,i,j+1, m, n);
        int down = rec(obstacleGrid,i+1,j, m, n);
        return dp[i][j] = side + down;
    }

    int uniquePathsWithObstacles_(vector<vector<int>>& obstacleGrid) {
       int m = obstacleGrid.size(),n = obstacleGrid[0].size();
       if(m == 1 && n == 1 && obstacleGrid[0][0] == 1) return 0; //edges case
       dp = vector<vector<int>>(m, vector<int>(n,-1));
       return rec(obstacleGrid,0,0,m,n);
    }
};