class MyQueue {
    private :
    stack<int>st;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        int size=st.size();
        vector<int>storage;
        while(!st.empty()){
            storage.push_back(st.top());
            st.pop();
        }
        st.push(x);
        for(int i=storage.size()-1;i>=0;i--){
            st.push(storage[i]);
        }
    }
    
    int pop() {
        int element=st.top();
        st.pop();
        return element;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */