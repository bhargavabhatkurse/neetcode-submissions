class Solution {
public:
    int bruteforce(vector<int>& heights) {
        //I need to find the lse and rse of each. My boundary will be lse+1 and rse-1 which will form the width and height will be the height of the element
        
        //bruteforce_ n^2 time
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


     vector<int> nse_func(vector<int>& arr) {
        vector<int> nse(arr.size());
        stack<int> st;

        for(int i = arr.size()-1; i>=0;i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) { //make either nse or pse as >=, not both to avoid double counting
                    st.pop();
            }
            if(st.empty())
                    nse[i] = arr.size(); //indice of not found
            else
            nse[i] = st.top();
            
            st.push(i); //push indices, not values
        }

        return nse;
    }

    vector<int> pse_func(vector<int>& arr) {
        vector<int> pse(arr.size());
        stack<int> st;

        for(int i = 0; i < arr.size();i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) { //here made >=
                    st.pop();
            }
            if(st.empty())
                    pse[i] = -1; //not found
            else
            pse[i] = st.top();
            
            st.push(i);
        }

        return pse;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        auto nse = nse_func(heights);
        auto pse = pse_func(heights);

        for(int i = heights.size()-1; i>=0;i--) {
          int height = heights[i];
          int right_most = nse[i] - 1;
          int left_most = pse[i] + 1;
          
          maxArea = max(maxArea, height * (right_most - left_most  + 1));
        }
        return maxArea;
    }
};
