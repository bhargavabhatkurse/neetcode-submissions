class MinStack {
public:
    stack<int> st;
    stack<int> minst; //tracks the min till that point (till that index if you might say)
    MinStack() {
       
    }
    
    void push(int val) {
        st.push(val);
        minst.push(min(val, minst.empty() ? val: minst.top()));
    }
    
    void pop() {
    st.pop();
    minst.pop(); //we have to pop this too  - remember 
    // Keep minStack aligned with the main stack after a pop.
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
