class Solution {
public:
unordered_map<int,int> dp;
//similar to coin change problem
    int rec(int n, vector<int>& perfects) {
      //n*rootn
        if(n == 0) return 0;
        int min_ = INT_MAX;

        if(dp.count(n)) return dp[n];

        for(int i = 0; i < perfects.size();i++){ //rootn
        if(n >= perfects[i])
        min_ = min(min_, 1+rec(n-perfects[i],perfects)); 
        }

        return dp[n] = min_;
    }

    int numSquares_(int n) {
       vector<int> perfects;

       for(int i = 1; i <= sqrt(n); i++) { //0 is not perfect square
        if(i*i <= n) perfects.push_back(i*i);
       } 

    //    for(auto i: perfects) {
    //     cout<<i<<" ";
    //    }
        
       return rec(n,perfects);

    }

     int numSquares(int n) {
        //bottom-up
       vector<int> dp(n + 1, n); //worst case of all 1s
        dp[0] = 0;  //base case

      for(int target = 1; target <= n;target++) {
         //for each target 
      for(int i = 1; i <= sqrt(target);i++){
        dp[target]= min(dp[target], 1+dp[target-i*i]); 
      }
     }
     return dp[n];
     }
};