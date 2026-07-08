class Solution {
public:
    vector<int> dp;
    int rec(vector<int>& nums, int i) {
        //dp: n2: n dp states, n tries for each state in worst case
        if(i >= nums.size()) return 1e9; //can't reach - infinite steps needed
        if(i  == nums.size()-1) return 0; //goal no more steps needed
        if(dp[i] != -1) return dp[i];
       int min_steps = 1e9;
       for (int jump = 1; jump <= nums[i] && i+jump < nums.size(); jump++) {
           min_steps= min(min_steps, 1+rec(nums,i+jump));
       }

        return dp[i] = min_steps;
    }
    
    int jump_topdown(vector<int>& nums) {
        dp.assign(nums.size(),-1);
        return rec(nums,0);
    }

        int jump_bottomup(vector<int>& nums) {
        dp.assign(nums.size(),1e9);
        dp[nums.size()-1] = 0; //no more jumps required from the last
        
        for(int i = nums.size()-2; i >=0; i--) {
        for(int jump = 1; jump <= nums[i] && i+jump < nums.size(); jump++) {
            dp[i]= min(dp[i], 1+dp[i+jump]);
        }
        }

        return dp[0];
    }
     int jump(vector<int>& nums) { 
        queue<pair<int,int>> q; //index and the steps
        vector<bool> visited(nums.size(), false);
       
        q.push({0,0}); //first index
        visited[0] = true;
        
        while(!q.empty()) {
            auto [i,steps] = q.front();
            q.pop();

           if(i == nums.size()-1) return steps;
           for(int jump = 1; jump <= nums[i] && i+jump < nums.size(); jump++) {
                if (!visited[i+jump]) {
                    q.push({i+jump,1+steps});
                    visited[i+jump] = true;
                }
           }
        }

        return -1;
     }
};
