class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //bruteforce
        int max_  = INT_MIN;
        for(int i = 0; i < nums.size();i++) {
            int cur_prod = 1;
            for(int j = i; j < nums.size();j++) {
                cur_prod *= nums[j];
                if(cur_prod > max_) {
                    max_ = cur_prod;
                }
            }
        }
        return max_;
    }
};
