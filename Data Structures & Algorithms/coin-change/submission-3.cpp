class Solution {
public:
    vector<int> dp;
    int coinChange_2D(vector<int>& coins, int amount) {
        
         //This will need 2d Dp
        int n = coins.size();
        int res = rec(coins,n-1, amount);
        return res>=1e9?-1:res;
    
    }

    int rec(vector<int> &coins, int i, int amount) {
    //this works but leads to 2D dp
    
        if(i < 0 ) return 1e9; //if I have no coin, I can't form the value amount
        if(amount == 0) return 0; //I need 0 coins to form the amount 0
        int res = rec(coins,i-1,amount); //don't take the ith coin

        if(coins[i] <= amount) { //if its possible to take the coin
            res  = min(res, 1 + rec(coins, i, amount - coins[i])); //I can reuse
        }

        return res;
    }


    vector<int> Dp;
    int coinChange_topdown(vector<int>& coins, int amount) {
        //1D DP
        int n = coins.size();
        Dp.assign(amount+1, -1);
        int res = func(coins, amount);
        return res>=1e9?-1:res;
    }

    int func(vector<int> &coins, int amount) {

        //the hint to think this is 1D is I just care about the amount, I don't care about coins because I have
        int res = 1e9; //big number
        if(amount == 0) return 0; //no coins required for 0 (not <= because it is not possible as I am always checking if its a valid coin)
        if(Dp[amount] != -1) return Dp[amount];

        for(int coin: coins) {
            if(amount - coin >= 0) //valid coin
            res = min(res, 1+func(coins,amount - coin));
            }
        
        return Dp[amount] = res;
        }

    
    int coinChange_Dp(vector<int>& coins, int amount) {
        //1D DP - bottom up
        int n = coins.size();
        Dp.clear();
        Dp.assign(amount+1, -1);

        int res = Dp[amount];
        return res>=1e9?-1:res;
    }

    int coinChange(vector<int>& coins, int amount) {
        //1D DP - BFS
        int n = coins.size();
        vector<bool> visited(amount + 1, false);
        queue<pair<int,int>> q;
        q.push({0,amount});
        visited[amount] = true;

        while(!q.empty()) {
            auto x = q.front();
            q.pop();

            if(x.second == 0) return x.first;

            for(int coin : coins) {
                if(coin <= x.second && !visited[x.second - coin])  {
                    visited[x.second - coin] = true;
                    q.push({x.first + 1, x.second - coin});
                }
            }
        }
        
        return -1;
    }
    
};
