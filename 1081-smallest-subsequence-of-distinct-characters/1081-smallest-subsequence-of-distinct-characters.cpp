class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        map<char,int>mp;
        set<char>sett;

        for(auto a:s)mp[a]++;

        stack<char>st;

        for(int i=0;i<n;i++){
                mp[s[i]]--;
                if(sett.count(s[i])!=0)continue;
                while(!st.empty() && s[i]<st.top() && mp[st.top()]>0){
                    sett.erase(st.top());
                    st.pop();
                }
            st.push(s[i]);
            sett.insert(s[i]);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};