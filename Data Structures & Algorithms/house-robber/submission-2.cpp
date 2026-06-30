class Solution {
public:
vector<int> dp;
//int maximum; if using this, make sure to intialise it to be value before taking max()
    int rec_forward(vector<int>& nums, int i) {
        //forward dp: 
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int money = max(rec_forward(nums,i+1),nums[i]+rec_forward(nums,i+2)); //skip this house or take it and skip next house
        return dp[i] = money;
    }

    int rec_backward(vector<int>& nums, int i) {
        //backward dp: 
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        int money = max(rec_backward(nums,i-1),nums[i]+rec_backward(nums,i-2));
        return dp[i] = money;
    }

    int rob_topdown(vector<int>& nums) {  
        //dp.assign(nums.size(),-1);  forward
         //return rec_forward(nums,0);

         dp.assign(nums.size(),-1);
         return rec_backward(nums,nums.size()-1);  
    }


    int rob_backward(vector<int>& nums) {
        //dp[i]: max profit till ith house 
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        
        vector<int> dp(nums.size());
        
        //base cases
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]); // I can skip 0 and take house 1

        for(int i=2;i<nums.size();i++) {
            dp[i] = max(dp[i-1],dp[i-2]+ nums[i]);
        }

        return dp[nums.size()-1];
    }

     int rob(vector<int>& nums) {
        //forward
        //dp[i]: max profit from ith house till end
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        int n = nums.size();
        vector<int> dp(n+1,0);
        
        //base cases
        dp[n-1] = nums[n-1];
    
        for(int i=n-2;i>=0;i--) {
            dp[i] = max(dp[i+1],dp[i+2]+ nums[i]);
        }

        return dp[0];
    }

   
};
