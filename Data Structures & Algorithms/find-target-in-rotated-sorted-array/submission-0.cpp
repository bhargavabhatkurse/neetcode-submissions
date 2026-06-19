class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;

        while(low<=high) {
            int mid = low + (high-low)/2;

            if(nums[mid] == target) return mid;

            if(nums[low] == nums[mid] && nums[mid] == nums[high]) { //can't determine which half is sorted
                low++;
                high--;
                continue; //important
             //this is to shrink on both sides by 1;
            }

            //otherwise, either the left half or the right half will be sorted
            if(nums[low] <= nums[mid]) { //left half is sorted
            if(nums[low] <= target && target <=nums[mid]) high = mid-1; //shrink to left half
            else low = mid+1; //shrink to right half
            }
            else { //right half is sorted
            if(nums[mid] <= target && target <=nums[high]) low = mid+1;
            else high = mid-1;
            }
        }
        return -1;
        
    }
};
