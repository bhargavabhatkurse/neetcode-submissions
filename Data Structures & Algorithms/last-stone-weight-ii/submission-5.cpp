class Solution {
public:
//basically like subset sum 
    vector<vector<int>> dp;
    int rec(vector<int>& stones,int i,int total, int sum, int target) {
        // Once we reach/exceed half, this is the best
        // we can do along this path.
        //recursion is conceptually building one partition, and the other partition is determined automatically.
        if(total >= target || i == stones.size())
             return abs(total - (sum - total)); //difference betwen 2 piles (abs() because if i == stones.size() condition is hit, total -(sum - total) might give negative)

        if(dp[i][total]!= -1) return dp[i][total];

        return dp[i][total] = min(rec(stones,i+1,total,sum,target),rec(stones,i+1,total+stones[i],sum,target)); 
    }

    int lastStoneWeightII_(vector<int>& stones) {
        int sum = accumulate(stones.begin(),stones.end(),0);
        int target = (sum + 1) / 2;//(ceil) //I want one of the piles to be close to target (so that when I take the difference with the other pile, the difference is minimum)
        
        dp.assign(stones.size(),vector<int>(sum+1,-1)); //total can go from 0 to sum
        return rec(stones,0,0,sum,target);
    }

     int lastStoneWeightII(vector<int>& stones) {
        //bottom up
        int sum = accumulate(stones.begin(),stones.end(),0);
        int target = (sum + 1) / 2; //this is a ceil (even floor will work for this problem because it is symmetrical)
        int n  = stones.size();
        dp.assign(n + 1, vector<int>(target, -1)); // I only need to take till target( no need to have dp till sum)

        // Base case: no stones left
        for(int total = 0; total < target; total++) {
            dp[n][total] = abs(total - (sum - total));
        }

        for(int i = stones.size()-1; i >=0; i--) {
            for(int total = 0; total < target; total++) {
                int nottake = dp[i+1][total]; //not take

                //take 
                int newtotal = total + stones[i]; //take the current stone
                
                int take;

                if(newtotal >= target) {
                   take = abs(newtotal - (sum - newtotal)); 
                }
                else {
                     take = dp[i+1][newtotal]; // take
                }
                dp[i][total] = min(take,nottake);
            }
        }

        for(auto i: dp) {
            for(auto j: i) {
                cout<<j<<" ";
            }
            cout<<endl;
        }
        
        return dp[0][0];
    }
};