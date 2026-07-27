class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //sliding window
        int l = 0;
        int sum = 0;
        int window = INT_MAX;
        for(int r = 0; r < nums.size();r++) {
            sum += nums[r];
    
                while(sum >= target) { //shrink
                    window = min(window,r-l+1); //update the current valid window first
                    sum = sum - nums[l];
                    l++;
                }
            }
        return window == INT_MAX ? 0: window;
    }
};