class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> st;
        for(auto op: operations) {
            if(op == "+") {
               int top = st.back();
               st.pop_back();
                int newTop = top + st.back();
                st.push_back(top);
                st.push_back(newTop); //added last two stack elements
            }
            else if(op == "C") {
                st.pop_back();
            }
            else if(op == "D") {
                int num = st.back();
                 st.push_back(2*num);
            }
            else st.push_back(stoi(op));
        }

        int ans = 0;

        ans = accumulate(st.begin(),st.end(),0);

        return ans;
    }
};