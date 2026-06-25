class Solution {
public:
    // int dp(vector<int>& nums, int target,int i, int sum) {
    //     //recursion - TLE;
    //     // if(i == i == nums.size() && sum == target) return 1;
    //     // if(i == nums.size()) return 0;

    //     // i == nums.size() because we don't want to miss on the decision for the last element
    //     if(i == nums.size()) return target == sum; //combined

    //     int add = dp(nums,target, i+1, sum + nums[i]);
    //     int sub = dp(nums, target, i+1, sum - nums[i]);

    //     return add + sub;
    // }

    vector<vector<int>> dp;
    int totalsum;
    int dp_func(vector<int>& nums, int target,int i, int sum) {
        //n*m space and time complexity - n lenth of aray and m is sum of elements
        if(i == nums.size()) return target == sum;

        if(dp[i][totalsum + sum] != INT_MIN) return dp[i][totalsum + sum];

        int add = dp_func(nums,target, i+1, sum + nums[i]);
        int sub = dp_func(nums, target, i+1, sum - nums[i]);

        return dp[i][totalsum + sum] = add + sub;
    }
    
    int findTargetSumWays_topdown(vector<int>& nums, int target) {
        totalsum = accumulate(nums.begin(), nums.end(),0); //adding all elements
        dp = vector<vector<int>>(nums.size(),vector<int>(2*totalsum+1, INT_MIN));
        //range is [-sum, 0, sum] = 2x+1
        //we will bias as totalsum + sum (as dp can't store negative index)

        // dp[i][totalsum + sum] => Number of valid sign assignments for nums[i...n-1] when the current sum is sum.
        //this is forward dp
        return dp_func(nums, target,0, 0);

        
    }

     int findTargetSumWays_bottomUp(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n+1); //(when no elements(0 elements) are considered + 1 to n) = n +1
        
        dp[0][0] = 1;  //one way: choose nothing -  to form the sum 0(second index) when there are 0 elements(first index)
        
        for(int i = 0; i < n; i++) { //iterate through all the elements
            for(auto p: dp[i]) { 
                dp[i+1][p.first + nums[i]] += p.second;
                  dp[i+1][p.first - nums[i]] += p.second;
            }
        }
        return dp[n][target];
        }

        int findTargetSumWays(vector<int>& nums, int target) {
        //space optimised bottom up
        
        //actually new state depends only on thew previous states, therefore we don't need to maintain all the earlier states
        //therefore, we only need to maintain 2 maps: dp and nextdp
        int n = nums.size();
        unordered_map<int,int> dp; //sum and its ways
        
        dp[0] = 1;  //one way: choose nothing
        
        for(int i = 0; i < n; i++) { //iterate through all the elements
        unordered_map<int,int> nextDp;

            for(auto p: dp) { 
                nextDp[p.first + nums[i]] += p.second;
                nextDp[p.first - nums[i]] += p.second;
            }

            dp = nextDp;
        }
        return dp[target];
        }


};
