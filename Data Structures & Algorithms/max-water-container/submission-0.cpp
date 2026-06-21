
class Solution {
public:
    int maxArea(vector<int>& heights) {
        // //bruteforce: o(n2), 0(1) space
        // int maxA = INT_MIN;
        // for(int i = 0; i< heights.size();i++) {
        //  for(int j = i+1; j < heights.size();j++) {
        //     int height = min(heights[i],heights[j]);
        //     int width = abs(j-i);
        //     maxA = max(maxA, height*width);
        //  }
        // }
        // return maxA;

        // 2 pointer
        int left = 0; 
        int right = heights.size()-1;
        int maxA = INT_MIN;

        while(left<right) {
            int curr_maxA = (right-left)*min(heights[right],heights[left]);
            maxA = max(maxA,curr_maxA);

            heights[left] < heights[right]? left++: right--;
            //move only the smaller height index : why?
        }
        return maxA;

    }
};
