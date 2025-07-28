class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int>st;
        int n=s.size();
        // stringstream ss(s);
        for(int i=0;i<n;i++){
            // if(isnum(s[i])){
            // if(){

            //     st.push(s[i]);
            // }
             if(s[i]=="+"){
                int count=0;
                // while(count<2&&!st.empty()){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    int num=b+a;
                    st.push(num);
                }
            else if(s[i]=="-"){
                int count=0;
                // while(count<2&&!st.empty()){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    int num=b-a;
                    st.push(num);
                } 
            else if(s[i]=="/"){
                int count=0;
                // while(count<2&&!st.empty()){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    int num=b/a;
                    st.push(num);
                }
            else if(s[i]=="*"){
                int count=0;
                // while(count<2&&!st.empty()){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    int num=b*a;
                    st.push(num);
                } 

            else{
                
                st.push(stoi(s[i]));
            }  
         }
        
    return st.top();
    }
};