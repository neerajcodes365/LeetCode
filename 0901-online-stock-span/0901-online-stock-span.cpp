class StockSpanner {
public:
    int index;
    stack<pair<int,int>>st;//value,index;


    StockSpanner() {
         index=-1;
         st.push({INT_MAX,-1});
    }
    
    int next(int price) {
        index++;
        cout<<"index = "<<index<<endl;
        int ans=1;
        while(!st.empty()&& st.top().first<=price){
            st.pop();
        }

        if(!st.empty()) ans=(index-st.top().second);

        if(st.empty()) cout<<"stack is empty "<<endl;
        cout<<" ans ="<<ans<<endl;
        st.push({price,index});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */