class Solution {
public:
vector<int> dp; 
    int dfs(vector<int>& cost, int i) {
        if(i >= cost.size()) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = cost[i] + min(dfs(cost,i+1), dfs(cost,i+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        //dp[i]: mincost from i to end
        dp.assign(cost.size(),-1);
        return min(dfs(cost, 0), dfs(cost, 1)); //either from 0 or 1
    }
};
