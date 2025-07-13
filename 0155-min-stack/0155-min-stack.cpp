class MinStack {
    private:
    stack<pair<int,int>>st;//stack element,minimun
    // queue<int>mini;
    // priority_queue<int,vector<int>,greater<int>>pq;
    // int mini=INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        // mini=min(val,mini);
        // if(pq.empty() || pq.top()>){

            if(!st.empty()){
                int mini=st.top().second;
                mini=min(val,mini);
                st.push({val,mini});
            }else{
                st.push({val,val});
            }
    }
    
    void pop() {
        // if(st.top()==pq.top()) pq.pop();
        st.pop();
    }
    
    int top() {
       return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */