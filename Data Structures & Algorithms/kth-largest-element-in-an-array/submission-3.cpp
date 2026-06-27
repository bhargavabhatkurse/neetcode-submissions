class Solution {
public: //worst case is still 0(n2) - already sorted
    int partition(vector<int>& nums, int low, int high) {
    //choosing the last as the pivot - new algorithm
        int pivot = nums[high];
        
        int j = low;

        for(int i = low; i < high; i++) //high is the pivot
        {
            if(nums[i] <= pivot) {
                swap(nums[i],nums[j]);
                j++;
            }
        }
        
        // swap(nums[j], pivot); this is wrong, pivot is not an element in the array
        swap(nums[j], nums[high]);  
        cout<<j;
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
        //k = k-1; //if we want to find the kth smallest
        return driver(nums, 0, nums.size()-1, k);
    }
};
