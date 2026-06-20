class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto& t: tokens) {
            if(t != "+" && t != "-" && t != "*" && t != "/") st.push(stoi(t));
              //isdigit() doesnt work here because it expects a character and we have a string
            //also there can be negative numbers in RPN.
            //therefore this is the standard way of handling numbers in this.
            
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
