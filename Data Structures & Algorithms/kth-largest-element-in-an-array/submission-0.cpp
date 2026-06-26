class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    //     priority_queue<int,vector<int>,greater<int>> minheap;

    //     for(int num: nums) {
    //         minheap.push(num);
    //         if(minheap.size() > k) //only keep k elements 
    //             minheap.pop();
    //     }

    // return minheap.top();

    //max heap: n + klogk or (nlogn + klogk)
    priority_queue<int,vector<int>> maxheap;
     for(int num: nums) {
            maxheap.push(num);
    }
    int ans;
    while(k-- > 0) {
        ans = maxheap.top();
        maxheap.pop();
    }
    return ans;
    }
};
