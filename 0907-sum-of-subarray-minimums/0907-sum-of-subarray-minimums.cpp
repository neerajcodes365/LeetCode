class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=n;
            }else{
                int index=st.top();
                nse[i]=index;
            }
            st.push(i);
        }
        while(!st.empty()){st.pop();}
        vector<int>pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i]=-1;
            }else{
                int index=st.top();
                pse[i]=index;
            }
            st.push(i);
        }
        int ans=0;
        int mod=1e9+7;
        for(int i=0; i<n;i++) {
            long long left=i-pse[i];
            long long right=nse[i]-i;
            long long total=(left*right)%mod;
            total=(total*arr[i])%mod;
            ans=(ans+total)%mod;
        }
        return ans;    
    }
};