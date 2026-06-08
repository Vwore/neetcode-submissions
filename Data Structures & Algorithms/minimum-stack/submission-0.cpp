class MinStack {
public:
    vector<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
       return st[st.size()-1];
    }
    
    int getMin() {
        int minVal =INT_MAX;
        for(int i=0;i<st.size();i++)
        {
            minVal = min(minVal,st[i]);
        }
        return minVal;
    }
};
