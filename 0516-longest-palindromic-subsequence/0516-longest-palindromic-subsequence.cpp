class Solution {
public:
    int lcs(string& s1,string& s2,int i,int j,vector<vector<int>>&dp){
        if(i<0 || j<0)return 0;
        
        if(s1[i]==s2[j]) return dp[i][j]=1 + lcs(s1,s2,i-1,j-1,dp) ;
        
        if(dp[i][j]!=-1)return dp[i][j];

        return dp[i][j]=max( lcs(s1,s2,i-1,j,dp),lcs(s1,s2,i,j-1,dp));
    }
    int longestPalindromeSubseq(string s) {
        
        string rev=s;
        reverse(rev.begin(),rev.end());
        // string rev=s.rbegin()
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        int n=s.size()-1;
        return lcs(s,rev,n,n,dp);
    }
};