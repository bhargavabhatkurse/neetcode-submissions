class Solution {
public:
    vector<vector<int>> dp;
    int rec(vector<int>& prices,int i,int BoS) {
        //BoS - buy1 or sell0 
        
        if(i >= prices.size()) return 0; //0 profit as no days are remaining
        
        if(dp[i][BoS] != -1) return dp[i][BoS];

        int profit;
        if(BoS) { //buying on the ith day
            profit = max(-prices[i] + rec(prices,i+1, false), //sell on the next day
                        0 + rec(prices,i+1, true) //can again buy on the next day
            );
        }   
        else { //selling on the ith day
                profit = max(prices[i] + rec(prices,i+2, true), //sell on the +2th day
                        0 + rec(prices,i+1, false)); //(you can think of this as selling and buying again on same day and moving to the next day (so the profit is 0 and essentially you wasted that day))
        }
        
        return dp[i][BoS] = profit;
    }

    int maxProfit_topdown(vector<int>& prices) {
        dp.assign(prices.size(),vector<int>(2,-1));
        int ans = rec(prices,0,true); //can buy on the first day
        
        //only dp[0][0] will not be calculated as you can't sell on first day itself (it is invalid)
            // -1 6 
            // 7 4 
            // 4 4 
            // 4 4 
            // 4 0 
            
        for(auto i: dp) {
            for(auto j: i)
            cout<<j<<" ";
            cout<<endl;
        }

        return ans;
    }

    int maxProfit(vector<int>& prices) {
        //0 is the least profit
        int n = prices.size();
        dp.assign(prices.size()+2,vector<int>(2,0)); //because we wil be accessing i+2 
        int profit; 
        for(int i = n-1;i >= 0; i--){
            for(int j = 0; j < 2; j++) {
                 if(j) { //buying on the ith day
                    profit = max(-prices[i] + dp[i+1][false], //sell on the next day
                                0 + dp[i+1][true] //can again buy on the next day
                    );
                }   
                else { //selling on the ith day
                        profit = max(prices[i] + dp[i+2][true], //sell on the +2th day
                                0 + dp[i+1][false]); //(you can think of this as selling and buying again on same day and moving to the next day (so the profit is 0 and essentially you wasted that day))
                }
                
               dp[i][j] = profit;
            }
    }
        return dp[0][1];
    }

};
