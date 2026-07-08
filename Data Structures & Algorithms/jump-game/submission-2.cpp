class Solution {
public:
    vector<int> dp;
    bool rec(vector<int>& nums, int i) {
        if(i >= nums.size()) return false;
        if(i  == nums.size()-1) return true;
        if(dp[i] != -1) return dp[i];
        
        bool possible = false;

       for (int jump = 1; jump <= nums[i] && i+jump < nums.size(); jump++) {
            // possible = possible || rec(nums,i+jump); //we should try to short circuit. We don't need to try all
            if(rec(nums,i+jump)) return dp[i] = true; //short circuit. no need to evaluate all
        }
        return dp[i] = false;
    }
    bool canJump_topdown(vector<int>& nums) {
        //topdown: n states: for each inner for loop runs n-i times in the worst case - therefore, n^2
        dp.assign(nums.size(),-1);
        return rec(nums,0);
    }

    bool canJump_bottomup(vector<int>& nums) {
        //bottom up -n^2
        dp.assign(nums.size(),false);
        dp[nums.size()-1] = true;

        for(int i=nums.size()-2; i >= 0;i--) {
            for (int jump = 1; jump <= nums[i] && i+jump < nums.size(); jump++) {
                // possible = possible || rec(nums,i+jump); //we should try to short circuit. We don't need to try all
                if(dp[i+jump] == true) 
                {
                    dp[i] = true; //short circuit. no need to evaluate all
                    break;
                }
            }
            //dp[i] == true? dp[i] = true: dp[i] == false; //I don't need this because full dp is false by default
        }
    
        for(int i: dp) cout<<i<<" ";

    return dp[0];


    }

     bool canJump(vector<int>& nums) { 
        int goal = nums.size()-1;

        for(int i = nums.size()-2; i >= 0; i--){
            if(i + nums[i] >= goal)
                goal = i;
        }

        return goal == 0;
     }
};
