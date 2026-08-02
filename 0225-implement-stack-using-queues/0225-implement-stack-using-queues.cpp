class MyStack {
public:
    MyStack() {
    }
    // deque<int>q;
    queue<int>q;

   
    void push(int x) {
        // q.push(x);
        int n=q.size();
        q.push(x);
        while(n){
            q.push(q.front());
            q.pop();
            n--;
        }
    }
    
    int pop() {
        int ele=q.front();
        q.pop();
        return ele;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.size()==0)return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */