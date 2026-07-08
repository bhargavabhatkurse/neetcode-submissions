class Solution {
public:
    vector<int> dp;
    bool rec(vector<int>& nums, int i) {
        if(i >= nums.size()) return false;
        if(i  == nums.size()-1) return true;
        if(dp[i] != -1) return dp[i];
        int jump  = nums[i];

        bool possible = false;

       for (int jump = 1; jump <= nums[i]; jump++) {
            // possible = possible || rec(nums,i+jump); //we should try to short circuit. We don't need to try all
            if(rec(nums,i+jump)) return dp[i] = true; //short circuit. no need to evaluate all
        }
        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        dp.assign(nums.size(),-1);
        return rec(nums,0);
    }
};
