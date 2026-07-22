class Solution {
public:
    int maxSubArray_(vector<int>& nums) {
    //when the array has negatives, sliding window can't decide whether to shrink or expand.
    //it needs some monotonicity or should have all elements non negative

    //bruteforce - try all subarray - o(n^2)
    int maximum = INT_MIN;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        int curr = 0;
    for(int j = i; j < n; j++) {
        curr += nums[j];
        maximum = max(curr,maximum);
    }
    }
    return maximum;
    }

    int maxSubArray(vector<int>& nums) {

    //0(n) -Kadane's Algo (negative numbers also there)

    int maximum = INT_MIN;

    int n = nums.size();

    int sum = 0, ansS = -1, ansE = -1,start = -1;
    for(int i = 0; i < n; i++) {
        if(sum == 0) start = i; //I always start the subarray when the sum is 0;
        sum += nums[i];
        
        if(sum > maximum) {
        //maximum = max(sum,maximum);
            maximum = sum;
            ansS = start; ansE = i;
        }

        if(sum < 0) {//2 -3 ... its better to avoid 2 and -3 as they will lead to -ve sum
            sum = 0;
        }

    }
    for(int i = ansS; i <= ansE;i++) cout<<nums[i]<<" ";
    // Input:
    //     nums=[2,-3,4,-2,2,1,-1,4]
    //     stdout:


    //     4 -2 2 1 -1 4 

    return maximum;
    }
};
