class MinStack {
public:
    stack<int>st;
    map<int,int>m;
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        st.push(x);
        m[x]++;
    }
    
    void pop() {
        m[st.top()]--;
        if(m[st.top()] == 0)
            m.erase(st.top());
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return m.begin()->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */