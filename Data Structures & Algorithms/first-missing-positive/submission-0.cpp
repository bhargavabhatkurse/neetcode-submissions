class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //nlogn soln
        sort(nums.begin(),nums.end());
        int smallest = 1;

        for(int i =0; i < nums.size();i++) {
            if(nums[i] == smallest) smallest++;
        }

        return smallest;
    }
    
};