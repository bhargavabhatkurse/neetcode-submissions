class Solution {
public:
    int partition(vector<int>& nums, int low, int high) {
        int pivot = low;
        int i = low + 1;
        int j = high;

        while(true) {
            while(i <= high && nums[pivot] >= nums[i]) {
                i++;
            }
             while(j >= low+1 && nums[pivot] < nums[j]) { //low+1 because low is the pivot itself
                j--;
             }
            if(i > j) break; //pointers should not cross each other 
            
            //if i <= j then swap
            swap(nums[i],nums[j]);
        }
        swap(nums[j], nums[pivot]);
        return j; //now j is the pivot
    }

    int driver(vector<int>& nums, int low, int high, int k) {
        if(low == high) return nums[low]; //only element
        
        int pivot = partition(nums, low, high);

        if(pivot == k) return nums[k];
        else if(pivot > k) return driver(nums, low, pivot-1, k);
        return driver(nums, pivot + 1 , high, k);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        //quick select finds the smallest at an index (0 based index)
        k = nums.size() - k; //this will give the index of the kth largest number
        return driver(nums, 0, nums.size()-1, k);
    }
};
