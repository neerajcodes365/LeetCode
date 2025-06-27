class Solution {
public:
    bool parseBoolExpr(string exe) {
        stack<int>st;
        vector<bool>vet;
        int n=exe.length();
        st.push(0);
        //1=and 2=or 3=not
        for(int i=0;i<n;i++){
            if(exe[i]=='&') st.push(1);
            if(exe[i]=='|') st.push(2);
            if(exe[i]=='!') st.push(3);
            if(exe[i]=='f') vet.push_back(false);
            if(exe[i]=='t') vet.push_back(true);
            if(exe[i]==')') break;
        }
        int first=st.top();
        st.pop();
        bool ans=vet[0];
        for(int i=1;i<vet.size();i++){
            if(first==1) ans=ans&&vet[i];
            if(first==2) ans=ans || vet[i];
            if(first==3) ans=ans && !vet[i];
        }
        int ni=st.top();
        while(ni){
            int tip=st.top();
            if(tip==1) ans=ans&&ans;
            if(tip==2) ans=ans || ans;
            if(tip==3) ans=!ans;
            st.pop();
            ni=st.top();
        }
        return ans;
    }
};