class Solution {
public:
    vector<vector<int>> dp;
    int rec(vector<int>& nums,int i, int m) {
        //rec(i,m): from ith index, we need to form m subarrays
        if(i == nums.size() && m == 0) return 0; //valid
        if(i == nums.size() ||  m == 0) return INT_MAX; //invalid: if only 1 of them is true
        if(dp[i][m] != -1) return dp[i][m];

        int cur_sum = 0, res = INT_MAX;

        for(int j = i; j < nums.size();j++) {
            cur_sum += nums[j];

            res = min(res, max(cur_sum, rec(nums,j+1,m-1))); //splitting at j
        }

        return dp[i][m] = res;
    }


    int splitArray(vector<int>& nums, int k) {
        dp.assign(nums.size(),vector<int>(k+1,-1));
        return rec(nums,0,k);
    }
};