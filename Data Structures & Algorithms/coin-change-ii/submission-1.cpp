class Solution {
public:
vector<vector<int>> dp;
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(n, vector<int>(amount+1,-1));
        // return rec(coins, n-1, amount); //backward
         return rec(coins, 0, amount); //forward
    }
     int rec(vector<int> &coins, int i, int amount) {
    // dp[i][amount] depends on i-1 : backward
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
