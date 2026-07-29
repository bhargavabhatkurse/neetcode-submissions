class Solution {
public:
    vector<vector<int>> dp;
    int dfs( vector<int>& nums, int i, int j) {
    //i - current element, j - the last chosen element in the subsequence
    if(i == nums.size()) return 0; //with no elements remaining, we can't make subseq
    
    if(dp[i][j+1] != -1) return dp[i][j+1]; //trick: shifting j as j+1 so that
    //the range goes from 0 to n;

    //in DP first do the not taken case and then the taken case
    int LIS = dfs(nums, i+1, j); //didnt take the ith element

    //if its the first element or larger than the previously chosen nums[j]
    if(j == -1 || nums[j] < nums[i])
    //valid
     {
        LIS = max(LIS, 1 + dfs(nums, i+1, i)); //i is the last chosen element now
     //we are taking max becuase recursion does 'not take' and also 'take' case. 
     //it doesnt know on its own which choice leads to longer.
     }

      return dp[i][j+1] = LIS;
    }

    int lengthOfLIS_top_down(vector<int>& nums) {
    int n = nums.size();
    dp = vector<vector<int>>(n,vector<int>(n+1,-1)); //j goes from -1 to n-1
    return dfs(nums, 0, -1);
        
    }

     int lengthOfLIS(vector<int>& nums) {
      //dp[i][j+1] where j is the index of the previously chosen element.

        int n = nums.size();

        dp = vector<vector<int>>(n+1,vector<int>(n+1,-1)); //j goes from -1 to n-1

        for(int j =-1; j < n; j++) { //add +1 bias
          dp[n][j+1] = 0;
        }

        for(int i = n - 1; i >=0; i--) {
         for(int j = 0;j <= n; j++) {
          int LIS = dp[i+1][j]; //didnt take the ith element

          //if its the first element or larger than the previously chosen nums[j]
          if(j-1 == -1 || nums[j-1] < nums[i])
          //valid
          {
              LIS = max(LIS, 1 + dp[i+1][i+1]); //i is the last chosen element now, BUT after biasing its (i)+1
          }
          dp[i][j] = LIS;
         }
        }

        return dp[0][0];
    }
};
