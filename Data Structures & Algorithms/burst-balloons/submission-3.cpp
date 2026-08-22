class Solution {
public:
    vector<vector<int>> dp; 
    int rec(vector<int>& nums, int i, int j) {
        if(i > j) return 0; //0 coins if the window doesnt exist (note: we need to keep i==j also as it is a window of size=1)
        int maxcoins = INT_MIN;
        if(dp[i][j] != -1) return dp[i][j];
        for(int idx = i; idx <= j; idx++) {
                int coins = rec(nums,i, idx-1) + nums[i-1]*nums[idx]*nums[j+1] + rec(nums,idx+1, j); // i-1 | i....j | j+1 (i-1 and j+1 are outside the interval)
                maxcoins = max(maxcoins, coins);
        }
        return dp[i][j] = maxcoins;
    }

    int maxCoins_topdown(vector<int>& nums) {
        //o(n^3) - No of states(n^2) x work per state (n)
        //add 1 at the beginning and at the end
        nums.insert(nums.begin(), 1);
        nums.push_back(1);    
        dp.assign(nums.size()+1,vector<int>(nums.size()+1,-1)); //because we only need to store from 0|1.......n| interval(DP only needs to represent balloon intervals, not the boundary 1s.)

        return rec(nums, 1, nums.size()-2);
    }

    int maxCoins(vector<int>& nums) {
        
        //add 1 at the beginning and at the end
        nums.insert(nums.begin(), 1);
        nums.push_back(1);    
        int n = nums.size()-2; //actual balloons

        dp.assign(nums.size(),vector<int>(nums.size(),0)); 

        for(int i = n; i>=1;i--)
        for(int j = i; j <=n;j++) {   
        int maxcoins = INT_MIN;  
        for(int idx = i; idx <= j; idx++) {
                int coins = dp[i][idx-1] + nums[i-1]*nums[idx]*nums[j+1] +  dp[idx+1][j];
                maxcoins = max(maxcoins, coins);
                dp[i][j] = maxcoins;
        }
        }
        return dp[1][n]; //interval


    }
};
