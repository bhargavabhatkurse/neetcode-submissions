class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int n = nums.size(), l =0, r = 0;
    //    l = where the next answer goes
    //    r = first element of the next group

       while(r < n) {
        nums[l] = nums[r];
        while(r < n && nums[l] == nums[r]) {
            r++;
        }
        l++;
       }
       return l;
    }
};