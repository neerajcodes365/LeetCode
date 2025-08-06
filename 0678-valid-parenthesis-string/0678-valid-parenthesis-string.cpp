/*
class Solution {
public:
        // map<char,int>
        // bool ans;
        int n;
        bool help(string s,int i,int total,map<pair<int,int>, bool>&dp){
            
            if(i>=n && total==0) {
                // ans=true;
                // return dp[i][total]=1;
                return dp[{i,total}]=1;
                }
            if(i>=n || total<0) return dp[{i,total}]=0;

            if(dp.count({i,total})) return dp[{i,total}];

            char ch=s[i];
            // cout<<ch<<endl;
            bool a=false;

            if(ch=='(') a= help(s,i+1,total+1,dp);
            else if(ch==')') a=help(s,i+1,total-1,dp);
            else{
                a= help(s,i+1,total,dp) || help(s,i+1,total+1,dp)|| help(s,i+1,total-1,dp);
            }

            return dp[{i,total}]=a;
       }

    bool checkValidString(string s) {

        n=s.length();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        map<pair<int,int>, bool> dp;// i ,total, 
        // ans=false;
        return help(s,0,0,dp);
        // return ans;
    }
};
*/

class Solution {
public:
    bool checkValidString(string s) {

        int n=s.length();

        stack<int>st;
        stack<int>star;

        int i=0;
        while(i<n){
            char ch=s[i];
            if(ch=='(') st.push(i);
            else if(ch=='*') {
                star.push(i);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }else if(!star.empty()){
                    star.pop();
                }
                else return false;
            }
            i++;
        }

            while(!st.empty()){
                // if()?
                // // st.pop();
                // if(star.empty()) return false;
                // else star.pop();
                // if()
                if(star.empty() || st.top()>star.top()) return false;
                else {
                    st.pop();
                    star.pop();
                }

            }
            return true;
        }
};