class Solution {
public:
vector<vector<int>> dp;
int change(int amount, vector<int>& coins) {
    //    space optimised
        int n = coins.size();
        vector<int> dp(amount+1,0), dpnext(amount+1,0);

        for(int j = 0; j <= amount; j++) dpnext[j] = 0; //no coins left, so can't form the amount
        
        dpnext[0] = 1; //remember this
        
        for(int i = n-1; i >=0; i--) {
            dp[0] = 1; //like this: for(int i = 0; i <= n; i++) dp[i][0] = 1;
           for (int j = 0; j <= amount; j++) { //this should go from 0 to amount
                dp[j] = dpnext[j]; //not taking the current coin i
                if (j >= coins[i]) //if possible to take using ith coin (index: i-1)
                    dp[j] += dp[j-coins[i]];//reuse the coin
           }
             dpnext = dp;
        }
        return dp[amount]; //remember this
    }

    int change_forward(int amount, vector<int>& coins) {
        //bottom up:
        // forward dp[i][amount]: using coin i to last coin coins [i....], how many ways can I form amount 
        int n = coins.size();
        dp.assign(n+1, vector<int>(amount+1,0));

        for(int j = 0; j <= amount; j++) dp[n][j] = 0; //no coins left, so can't form the amount
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        
        for(int i = n-1; i >=0; i--)
           for (int j = 0; j <= amount; j++) { //this should go from 0 to amount
                dp[i][j] = dp[i+1][j]; //not taking the current coin i
                if (j >= coins[i]) //if possible to take using ith coin (index: i-1)
                    dp[i][j] += dp[i][j-coins[i]];//reuse the coin
        }

        return dp[0][amount]; //remember this
    }

    int change_backward(int amount, vector<int>& coins) {
        //bottom up:
        // backward dp[i][amount]: using first i coins, how many ways can I form amount 
        int n = coins.size();
        dp.assign(n+1, vector<int>(amount+1,0));

        for(int i = 0; i <= n; i++) dp[i][0] = 1; //using 0 coins, forming amount 0
        
        for(int i = 1; i <=n; i++)
            for(int j = 1; j <=amount; j++) {
                dp[i][j] = dp[i-1][j]; //not taking the current coin i
                if (j >= coins[i-1]) //if possible to take using ith coin (index: i-1)
                    dp[i][j] += dp[i][j-coins[i-1]];
        }

        return dp[n][amount];
    }

    int change_topdown(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(n, vector<int>(amount+1,-1));
        //return rec(coins, n-1, amount); //backward
        return rec(coins, 0, amount); //forward
    }

     int rec(vector<int> &coins, int i, int amount) {
    // dp[i][amount] depends on i+1 : forward
        if(i == coins.size() ) return 0; //no soln: if I have no coin, I can't form the value amount
        
        if(amount == 0) return 1; //I have found 1 soln
        
        if(dp[i][amount] != -1) return dp[i][amount];

        int res = rec(coins,i+1,amount); //don't take the ith coin

        if(coins[i] <= amount) { //if its possible to take the coin
            res  += rec(coins, i, amount - coins[i]); //I can reuse
        }

        return dp[i][amount] = res;


    }

    int rec_backward(vector<int> &coins, int i, int amount) {
    // dp[i][amount] depends on i-1 : backward
        if(i < 0 ) return 0; //no soln: if I have no coin, I can't form the value amount
        if(amount == 0) return 1; //I have found 1 soln
        
        if(dp[i][amount] != -1) return dp[i][amount];

        int res = rec(coins,i-1,amount); //don't take the ith coin

        if(coins[i] <= amount) { //if its possible to take the coin
            res  += rec(coins, i, amount - coins[i]); //I can reuse
        }

        return dp[i][amount] = res;
    }
};
