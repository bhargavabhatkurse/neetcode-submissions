class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto& t: tokens) {
            if(t != "+" && t != "-" && t != "*" && t != "/") st.push(stoi(t));

            else {
                int j = st.top();
                st.pop();
                int i = st.top();
                st.pop();
                int x;
                if (t == "+") x = i + j;
                else if (t == "-") x = i - j;
                else if (t == "*") x = i * j;
                else if (t == "/") x = i / j;
                
                st.push(x);
            }
        }

        return st.top();
    }
};
