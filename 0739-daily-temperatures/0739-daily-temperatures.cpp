class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        // while()
        vector<int>ans(n,0);
        stack<pair<int,int>>st;//num,index

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temp[i]>=st.top().first){
                st.pop();
            }
            // if(st.empty()){
            //     st.push({temp[i],i});

            //     ans[i]=0;
            //     cout<<"i ="<<i<<" ,ans[i]= "<<ans[i]<<endl;
            //     // continue;
            // }else{
            //     ans[i]=(st.top().second - i);
            //     cout<<"i ="<<i<<" ,ans[i]= "<<ans[i]<<endl;
            //     st.push({temp[i],i});
            // }
            if(!st.empty()){
                ans[i]=st.top().second-i;
            }

            st.push({temp[i],i});
            
        }
        return ans;
        
    }
};