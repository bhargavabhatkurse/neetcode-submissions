class Solution {
public:
    int trap(vector<int>& height) {
    //     //bruteforce - o(n^2)
    //     int water = 0;  
    //     for(int i = 0; i < height.size(); i++) {
    //         int left_greater = height[i]; //important 
    //         int right_greater = height[i];
    //     for(int j = 0; j <= i; j++)  //including i (to handle the edge case i = 0 pr i = n-1)
    //             left_greater = max(left_greater, height[j]);
    //     for(int j = i+1; j < height.size(); j++) 
    //              right_greater = max(right_greater, height[j]);
     
    //      int water_at_index  = min(left_greater, right_greater) - height[i];

    //     water += water_at_index;
    // }
    // return water;

    // //prefix-array o(n) and also o(n) space
    // int water = 0;
    // int n = height.size();
    // vector<int> left_greater(n,-1);
    // vector<int> right_greater(n,-1);

    // left_greater[0] = height[0];
    // for(int i = 1; i < height.size(); i++) 
    // left_greater[i] = max(left_greater[i-1],height[i]); //we want to include i also for edge case
    
    // right_greater[n-1] = height[n-1];
    // for(int i = n-2; i >= 0; i--) 
    // right_greater[i] = max(right_greater[i+1],height[i]); //we want to include i also for edge case
    
    // for(int i = n-1; i >= 0; i--) {
    // water += min(left_greater[i], right_greater[i]) - height[i];
    // }

    // //we are including the index i because the water formula is based on the tallest wall available on each side, and the current bar itself is always a valid candidate
    //     return water;
       
    // 
    
    //two pointer approach
    int res  = 0;
    int left = 0, right = height.size() -1;

    int leftM = height[left], rightM = height[right]; //tracks the maximum on both sides encountered so far

    while(left < right) {
        if(leftM < rightM) { //left bar is the limiting factor
        left++; //we need to do this because bar at current l is already processed
        //eg: l = 0 is hte initialising case;
        leftM = max(leftM, height[left]);
        res += leftM - height[left];
        }
        else {
        right--; //we need to do this because bar at current r is already processed
        //eg: r = n-1 is hte initialising case;
        rightM = max(rightM, height[right]);
        res += rightM - height[right];
        }
    }
    return res;



    //stack version is remaining
    }


};
