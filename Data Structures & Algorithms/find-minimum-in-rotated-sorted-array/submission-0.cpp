class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0, high = nums.size()-1;
        int minimum = INT_MAX;
        int index = -1; //to find the index of the minimum one
        //using this, we can find how many times the array was rotated
        int mid;
        while(low <= high) {
        mid = low + (high-low)/2;

        if(nums[low] <= nums[mid]) { //left half is sorted
            //the min element will be at the start of the sorted portion
            
            //minimum = min(minimum, nums[low]); 

            if(minimum > nums[low]) { //same thing as using the min function but track also the index
                minimum = nums[low];
                index = low;
            }
 
            low = mid + 1; //I can discard this left portion now
        }
        else { //right half is sorted
            //minimum = min(minimum, nums[mid]); //mid element is the minimum one
            if(minimum > nums[mid]) { //same thing as using the min function but track also the index
                minimum = nums[mid];
                index = mid;
            }
            
            high = mid-1;
        }
        }
        cout<<index; //not asked in this question, but this tells how many times the array was rotated
        return minimum;
        
    }
};
