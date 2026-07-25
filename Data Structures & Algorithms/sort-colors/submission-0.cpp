class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Dutch National Flag
        int i =0, l = 0, r = nums.size()-1;

        while(i <= r) {
            if(nums[i] == 0) {
                swap(nums[i],nums[l]);
                l++;
                i++;
            }
            else if(nums[i] == 2) {
                swap(nums[i],nums[r]);
                r--;
                //don't change i here
            }
            else {
                i++; //if the number is 1
            }   
        }
    }
};