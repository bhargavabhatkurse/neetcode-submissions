class Solution {
public:
    vector<int> dp;
    int rec(vector<int>& nums, int i) {
        if(i >= nums.size()) return 1e9; //can't reach - infinite steps needed
        if(i  == nums.size()-1) return 0; //goal no more steps needed
        if(dp[i] != -1) return dp[i];
       int min_steps = 1e9;
       for (int jump = 1; jump <= nums[i] && i+jump < nums.size(); jump++) {
           min_steps= min(min_steps, 1+rec(nums,i+jump));
       }

        return dp[i] = min_steps;
    }
    
    int jump(vector<int>& nums) {
        dp.assign(nums.size(),-1);
        return rec(nums,0);
    }
};
