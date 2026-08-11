class Solution {
public:
    vector<vector<int>> dp;
    int rec(vector<int>& stones,int i,int total, int sum, int target) {
        if(total >= target || i == stones.size())
             return abs(total - (sum - total)); //difference betwen 2 piles

        if(dp[i][total]!= -1) return dp[i][total];

        return dp[i][total] = min(rec(stones,i+1,total,sum,target),rec(stones,i+1,total+stones[i],sum,target)); 
    }

    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(),stones.end(),0);
        int target = ceil(sum/2); //I want one of the piles to be close to target (so that when I take the difference with the other pile, the difference is minimum)
        
        dp.assign(stones.size(),vector<int>(sum+1,-1));
        return rec(stones,0,0,sum,target);
    }
};