class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        if(num.size()<=k) return "0";
        // int count=1;
        int i=0;
        int size=num.length();
        
        while(i<size){
            while(k>0 && !st.empty() && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i++]);
        }

        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()) {
            ans+=st.top();
            st.pop();
    }
    reverse(ans.begin(),ans.end());
    i=0;
    while(i<ans.size() && ans[i]=='0')i++;

    ans=ans.substr(i);
        return ans=="" ? "0":ans;
        
    }

};