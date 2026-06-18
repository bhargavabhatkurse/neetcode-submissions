class Solution {
public:
    int search(vector<int>& nums, int target) {
    //     int low=0, high = nums.size();
    //     int mid;
    //     while(low<=high) {
    //     mid = low + (high - low)/2;
    //     if(nums[mid] == target) return mid;
    //     else if (nums[mid] < target) low = mid+1;
    //     else high = mid-1;
    //     }
    // return -1;

    //upper bound - first index greater than the target
    // int low=0, high = nums.size()-1;  ans = nums.size(); //possible upper bound
    // int mid;
        
    //     while(low<=high) { //this condition is important [l,r)
    //     mid = low + (high - low)/2;
    //     if(nums[mid] > target) {ans = mid; high = mid-1;} //my target 
    //     else low = mid+1; //shrink the left half
    //     }
    // return nums[ans-1] == target ? ans-1: -1;
    
    int low=0, high = nums.size()-1, ans = nums.size(); //possible lower bound
    int mid;
        
        while(low<=high) { //this condition is important [l,r)
        mid = low + (high - low)/2;
        if(nums[mid] >= target) {ans = mid; high = mid-1;} //my target 
        else low = mid+1; //shrink the left half
        }
    return nums[ans] == target ? ans: -1;


    }
};
