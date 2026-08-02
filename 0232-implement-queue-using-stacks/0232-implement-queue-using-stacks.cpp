class MyQueue {
    private :
    stack<int>st;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        // st.push(x);
        int n=st.size();
        stack<int>help;
        while(n--){
            // st.push()
            int ele=st.top();
            st.pop();
            help.push(ele);
        }
        st.push(x);
        int m=help.size();
        while(m--){
            int ele=help.top();
            help.pop();
            st.push(ele);
        }
    }
    
    int pop() {
        int ele=st.top();
        st.pop();
        return ele;
    }
    
    int peek() {
       return st.top();
    }
    
    bool empty() {
        if(st.size()==0)return true;
        return false;
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