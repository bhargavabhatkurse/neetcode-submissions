class Solution {
public:
    int two_pointer(vector<int>& prices) {
        // Cheaper buying price is always better.

        //Two pointer approach
        int l = 0; //buy
        int r = 1; //sell
        int maxprofit = 0;

       for(;r < prices.size();r++) {
            if(prices[r] > prices[l]) //sell price is better than buy price
            maxprofit = max(maxprofit, prices[r] - prices[l]);
            
            else l = r; //we have found a better buy price
        }
         return maxprofit;
       }

       int maxProfit(vector<int>& prices) {
       //track lowest price seen so for current i;
       // DP
       int n = prices.size();
      //  vector<int> lowest(n);
      //  vector<int> profit(n);
      //  lowest[0] = prices[0], profit[0] = 0;
      //  for(int i = 1; i < prices.size();i++) {
      //       lowest[i] = min(lowest[i-1], prices[i]);

      //       profit[i] = max(profit[i-1], prices[i] - lowest[i]);
      //  }
       
      //    return profit[n-1];

      //same thing but space optimised
        int lowest = prices[0], profit = 0;
       for(int i = 1; i < prices.size();i++) {
            lowest = min(lowest, prices[i]);
            profit = max(profit, prices[i] - lowest);
       }
       
         return profit;

       }
};
