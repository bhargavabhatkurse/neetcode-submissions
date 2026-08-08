class Solution {
public:
    // int rec(vector<int>& nums,int i, int sum, int target) {
    //     //this approach doesnt work because we need 1,2 and also 2,1(so order doesnt matter for this question)
    //     if(sum > target) return 0;
    //     if(sum == target) return 1;
        
    //     if(i == nums.size()) return 0;
        

    //     int taken = rec(nums,i,sum+nums[i],target);
    //     int not_taken = rec(nums,i+1,sum,target);

    //     return taken + not_taken;
    // }

    vector<int> dp;

    int rec(vector<int>& nums,int target) {
        //at every state, we use all the numbers of the array
        if(target == 0) return 1; //always check for solution first before bounds
        
        //if(target < 0) return 0; //we don't need this anymore
        
        if(dp[target] != -1) return dp[target];
        int res = 0;
        for(int num: nums) {
            if(target < num) break; //this works because we have sorted the array
            res += rec(nums,target-num);
        }

        return dp[target] = res;
    }

    int combinationSum4(vector<int>& nums, int target) {
        // dp.assign(target+1,-1);
        // sort(nums.begin(), nums.end());
        // return rec(nums,target);


        //bottom up: 
        sort(nums.begin(), nums.end());
        dp.assign(target+1,-1);
       
        dp[0] = 1; //base case

        for(int target_ = 1; target_<= target;target_++) { 
        int res = 0;
        for(int num: nums) {
            if(target_ < num) break; //this works because we have sorted the array
            res += dp[target_- num];
        }
            dp[target_] = res;
        }
        return dp[target];
    }
};