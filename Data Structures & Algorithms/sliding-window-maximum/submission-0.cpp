class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       

        // //bruteforce - o(n * k(search for max))
        // vector<int> result;
        // for(int i = 0; i < nums.size()-k + 1;i++) {
        //     vector<int> window;
        //     window.push_back(nums[i]);
        //     window.push_back(nums[i+1]);
        //     window.push_back(nums[i+2]);
        // int max = *max_element(window.begin(), window.end());
        // result.push_back(max);
        // }
        //     return result;
        // }

        // //heap - (n*logn) heapify is logn * n pushes of each element
        // priority_queue<pair<int,int>, vector<pair<int,int>>> pq; //(value, index)
        // vector<int> result;
        // for(int i = 0; i < nums.size();i++) { //goes till k because we are tracking the window from behind
        //     pq.push({nums[i],i});
        //     if(i >= k - 1) {//enough to form a window (only first window has to be formed)
        //     while(pq.top().second <= i-k) //window: [i-k+1, i]
        //         pq.pop();
        //     result.push_back(pq.top().first);
        //     }
        // }
        // return result;
        // }

        //using DP: so that we don't have to recalculate maximum each time
        int n = nums.size();
        vector<int> leftMax(n); //max at position i in the block from the start of the block
        vector<int> rightMax(n);//max at position i in the block from the end of the block

        leftMax[0] = nums[0];
        rightMax[n-1] = nums[n-1];

        for(int i  = 1; i <= n-1; i++) {
            //leftMax calculation
            if(i % k == 0) //start of the block from left side
            {
                leftMax[i] = nums[i]; //the number itself is the minimum
            }
            else {
                leftMax[i] = max(leftMax[i-1],nums[i]); //max from the start of the block
            }

            //RightMax calculation
            if(((n-i-1) % k) == 0) { //end of the block
                rightMax[n-i-1] = nums[n-i-1];
            }
            else {
                rightMax[n-i-1] = max(rightMax[(n-i-1) + 1],nums[n-i-1]);
            }
        }

        //important calculation for sliding window
        //a window might cross max of two blocks (because for precalculation we have divided into k fix blocks)
        vector<int> result(n-k+1); //no. of windows
        for(int i = 0; i < n-k+1; i++) {
            result[i] = max(rightMax[i],leftMax[i+k-1]); //remember: extremely important (visualise)
        }
        return result;


        



    }
};

