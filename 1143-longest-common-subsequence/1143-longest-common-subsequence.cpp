class Solution {
public:
    int help(int t1,int t2,string& text1,string& text2,vector<vector<int>>&dp){
        if(t1==text1.length()|| t2==text2.length()) return 0;
        if(dp[t1][t2]!=-1) return dp[t1][t2];
        if(text1[t1]==text2[t2]) {
            dp[t1][t2]=1+help(t1+1,t2+1,text1,text2,dp);
        }else{
            dp[t1][t2]=max(help(t1+1,t2,text1,text2,dp),help(t1,t2+1,text1,text2,dp));
        }
        return dp[t1][t2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int len1=text1.length();
        int len2=text2.length();
        int t1=0;
        int t2=0;
        vector<vector<int>>dp(len1,vector<int>(len2,-1));
        return help(t1,t2,text1,text2,dp);
    }
};