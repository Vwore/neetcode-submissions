class MinStack {
public:
    vector<int> st;
    vector<int> minSt;
    int minVal;

    MinStack() {
    }
    
    void push(int val) {
        st.push_back(val);
        if(minSt.size() == 0 || minSt[minSt.size()-1] >val)
        {
            minSt.push_back(val);
        }
        else minSt.push_back(minSt[minSt.size()-1]);
    }
    
    void pop() {
        minSt.pop_back();
        st.pop_back();
    }
    
    int top() {
       return st[st.size()-1];
    }
    
    int getMin() {
        
        return minSt[minSt.size()-1];
    }
};
