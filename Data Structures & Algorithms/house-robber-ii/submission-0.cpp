class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        return max(rob1_soln(vector<int>(nums.begin() + 1, nums.end())), //if we rob first one, we can't rob the last
                        rob1_soln(vector<int>(nums.begin(), nums.end() - 1))); //and vice versa
    }

    int rob1_soln(vector<int> nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp.back();
    }
};