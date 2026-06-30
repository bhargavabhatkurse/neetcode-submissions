class Solution {
public:
vector<int> dp; 
    int dfs(vector<int>& cost, int i) {
        if(i >= cost.size()) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = cost[i] + min(dfs(cost,i+1), dfs(cost,i+2));
    }
    int minCostClimbingStairs_topdown(vector<int>& cost) {
        //dp[i]: mincost from i to end
        dp.assign(cost.size(),-1);
        return min(dfs(cost, 0), dfs(cost, 1)); //either from 0 or 1
    }

    int minCostClimbingStairs_bottomup(vector<int>& cost) { 
        int n = cost.size();
        dp.assign(n+2,0);
        //dp[n+1] = 0; not required

        for(int i = n-1;i>=0;i--) {
        dp[i] = cost[i] + min(dp[i+1],dp[i+2]);
        }
        return min(dp[0],dp[1]);
    }

    int minCostClimbingStairs(vector<int>& cost) { 
        //space optimised
       int n = cost.size();
       int dp, dpnext = 0, dpnext2 = 0; 
        for(int i = n-1;i>=0;i--) {
        dp = cost[i] + min(dpnext,dpnext2);
        dpnext2 = dpnext;
        dpnext = dp;
        }

        return min(dpnext,dpnext2);
    }
};
