class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        vector<int> res(temperatures.size(),0);

        for(int i=0; i < temperatures.size(); i++) {
            while(!st.empty() && temperatures[i] > st.top().first) { //first element which breaks the monotonically decreasing trend
                auto x = st.top();
                st.pop();
                res[x.second] = i - x.second;
            }
            
            st.push({temperatures[i],i}); //push as long as monotonically decreasing

        }
        return res;
    }
};
