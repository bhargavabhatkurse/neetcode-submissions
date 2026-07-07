class Solution {
public:
    bool rec(vector<int>& nums,int i, int sum) {
        
        if(sum == 0) return true;

        if( i == nums.size()) return false;

        if(rec(nums, i+1, sum)) return true; //this way it is better to short-circuit
        
        if(nums[i] <= sum)
        return rec(nums, i+1, sum - nums[i]);
        
        return false;
        
    
        // //what I tried and worked
        // bool curr;
        // if(i == nums.size()) return sum == 0;
        // curr  = rec(nums, i+1, sum);
        // if(nums[i] <= sum)
        // curr |= rec(nums, i+1, sum - nums[i]);

        // return curr;
    }

    vector<vector<int>> dp; 
    bool rec_topdown(vector<int>& nums,int i, int sum) {
        if(sum == 0) return true;
    
        if(i == nums.size()) return false;

        if(dp[i][sum] != -1) return dp[i][sum];
        
        bool x = rec_topdown(nums, i+1, sum); 
        
        if(nums[i] <= sum)
        x = x || rec_topdown(nums, i+1, sum - nums[i]);
        
        return dp[i][sum] = x;
       
    }


   
    bool canPartition_topdown(vector<int>& nums) {
        int sum = 0;
        for(auto i: nums) sum += i;

        if((sum&1) != 0) return false;
        dp.assign(nums.size(),vector<int>(sum/2 + 1,-1));
        return rec_topdown(nums,0,sum/2);
    }
     
     
     vector<vector<bool>> Dp; 
     bool canPartition_forward(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;
        int n = nums.size();

        Dp.assign(n + 1, vector<bool>(target + 1, false));


        Dp[n][0] = true;
        //forward dp
        for(int i = n-1; i >= 0; i--) 
        for(int j = target; j >= 0; j--) {
        Dp[i][j] = Dp[i+1][j];
        if(nums[i] <= j)
        Dp[i][j] = Dp[i][j] || Dp[i+1][j-nums[i]];
     }

     return Dp[0][target];
     }

     bool canPartition(vector<int>& nums) {
        //backward DP
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;
        int n = nums.size();

        Dp.assign(n + 1, vector<bool>(target + 1, false));

        for (int i = 0; i <= n; i++) {
            Dp[i][0] = true;
        }

        //forward dp
        for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= target; j++) {
        Dp[i][j] = Dp[i-1][j];
        if(nums[i-1] <= j)
        Dp[i][j] = Dp[i][j] || Dp[i-1][j-nums[i-1]];
     }

     return Dp[n][target];
     }
};
