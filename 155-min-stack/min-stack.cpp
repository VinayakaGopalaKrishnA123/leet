class MinStack {
public:
    stack<int> st;
    stack<int> mst;
    MinStack() {
    }
    
    void push(int value) {
        if(st.empty()) mst.push(value);
        else if(value<=mst.top()){
            mst.push(value);
        }
        st.push(value);
    }
    
    void pop() {
        if(st.top()==mst.top()) mst.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */