class Solution {
public:
    int maxProduct_brute(vector<int>& nums) {
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
    
    
    int maxProduct(vector<int>& nums) {
        //the max product will either be prefix or the suffix
        int max_ = INT_MIN;

        int prefix = 1, suffix = 1;
        for(int i =0; i < nums.size();i++) {
           
            prefix *= nums[i];
            suffix *= nums[nums.size()-i-1];
            max_ = max(max_,max(prefix,suffix));
            
            //remember to reset in case of 0
            if(nums[i] == 0) prefix = 1;
            if(nums[nums.size()-i-1] == 0) suffix = 1;
        }

        return max_;
    }
};
