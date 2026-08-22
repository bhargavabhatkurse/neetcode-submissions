class Solution {
public:
    vector<vector<int>> dp; 
    int rec(vector<int>& nums, int i, int j) {
        if(i > j) return 0; //0 coins if the window doesnt exist (note: we need to keep i==j also as it is a window of size=1)
        int maxcoins = INT_MIN;
        if(dp[i][j] != -1) return dp[i][j];
        for(int idx = i; idx <= j; idx++) {
                int coins = rec(nums,i, idx-1) + nums[i-1]*nums[idx]*nums[j+1] + rec(nums,idx+1, j);
                maxcoins = max(maxcoins, coins);
        }
        return dp[i][j] = maxcoins;
    }

    int maxCoins(vector<int>& nums) {
        
        //add 1 at the beginning and at the end
        nums.insert(nums.begin(), 1);
        nums.push_back(1);    
        dp.assign(nums.size()+1,vector<int>(nums.size()+1,-1)); 

        return rec(nums, 1, nums.size()-2);
    }
};
