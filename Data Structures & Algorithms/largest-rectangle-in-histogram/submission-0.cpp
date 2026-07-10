class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //I need to find the lse and rse of each. My boundary will be lse+1 and rse-1 which will form the width and height will be the height of the element
        int n = heights.size();
        int maxArea = 0;

        for(int i = 0; i < n;i++) //for each element, find the max rect it can form
        {   
            int height = heights[i];
            int right_most = i+1;
            while(right_most < n && heights[right_most] >= height)
                right_most++;

            int left_most = i;
            while(left_most >=0 && heights[left_most] >= height)
                left_most--;


            left_most += 1;
            right_most -= 1;

            maxArea = max(maxArea, height * (right_most - left_most  + 1));
        }

            return maxArea;


    }
};
