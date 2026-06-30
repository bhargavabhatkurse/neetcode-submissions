class Solution {
public:
vector<int> dp;
//int maximum; if using this, make sure to intialise it to be value before taking max()
    int rec(vector<int>& nums, int i) {
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int money = max(rec(nums,i+1),nums[i]+rec(nums,i+2));
        return dp[i] = money;
    }
    int rob(vector<int>& nums) {  
        dp.assign(nums.size(),-1);  
        return rec(nums,0);
        
    }


    int rob1(vector<int>& nums) {
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

   
};
