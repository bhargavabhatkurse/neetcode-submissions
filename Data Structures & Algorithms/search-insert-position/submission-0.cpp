class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //lower bound
        int l = 0, r = nums.size()-1;
        int ans = nums.size();

        while(l <= r) {
            int mid = l + (r-l)/2;
            
            if(nums[mid] == target) return mid; //we don't do this for lower bound or upper bound
            else if(nums[mid] > target) {
                    ans = mid;
                    r = mid - 1;
            }
            else  l = mid+1;
        }

        return ans;
    }
};