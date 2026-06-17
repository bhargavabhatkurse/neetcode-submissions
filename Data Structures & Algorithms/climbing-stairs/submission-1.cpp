class Solution {
public:
    vector<int> dp;
    int rec_top_down(int i, int n) {
        //In recursive DP, always check boundary/base cases before accessing 
        //memoization arrays if the recursive calls can generate indices outside the DP table.
        
        //from the perspective of top
        if(i>=n) return i==n; //1 way if on the nth stair
        if(dp[i] != -1) return dp[i];
        return dp[i] = rec_top_down(i+1,n) + rec_top_down(i+2,n); //from ith step
    }

    int climbStairs(int n) {
        // dp.resize(n,-1); //becuase n = 1 to n, not 0 to n
        // return rec_top_down(0,n);
        
        // //bottom up: 
        // dp.resize(n+1,-1);
        // dp[1] = 1;
        // dp[2] = 2;

        // for(int i=3;i<=n;i++) {
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        
        // return dp[n];

        //bottom up space optimised: 
        if(n<=2) return n;
        int first = 1;
        int second = 2;
        int dp;
        for(int i=3;i<=n;i++) {
            dp = first + second;
            first = second;
            second = dp;
        }
        return dp;
        
        //going from n to 1 stairs
        // if(n==1) return 1;
        // if(n==2) return 2;
        // return climbStairs(n-1) + climbStairs(n-2);
    }
};
