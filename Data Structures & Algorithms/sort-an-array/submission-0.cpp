class Solution {
public:
    void merge(vector<int>& nums,int l, int mid, int r) {
        vector<int> b; 
        int low = l, high = mid+1;
        while(low <= mid && high <= r) {
            if(nums[low] < nums[high]) 
                b.push_back(nums[low++]);
            else
                 b.push_back(nums[high++]);
        }
        while(low <= mid) b.push_back(nums[low++]);
        while(high <= r) b.push_back(nums[high++]);

        //copy back
        for (int i = l; i <= r; i++)
            nums[i] = b[i - l];
        
    }

    void mergesort(vector<int>& nums,int l, int r) {
        if(l >= r) return; // = because there can remain only 1 element

        int mid = l + (r-l)/2;
        mergesort(nums,l,mid);
        mergesort(nums,mid+1,r);
        merge(nums,l,mid,r);
    }



    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};