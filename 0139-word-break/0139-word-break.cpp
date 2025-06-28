class Solution {
public:
    bool help(string& s,int i,int j,vector<vector<int>>&dp){
        if(i>j)return false;
        if(dp[i][j]!=-1)return dp[i][j];
        if(dp[i][j]==1)return true;
        bool ans=false;
        for(int k=i;k<=j;k++){
            if(dp[i][k]==1){
                ans=ans||help(s,k+1,j,dp);
            }
        }
        return dp[i][j]=ans;
    }

    bool wordBreak(string s,vector<string>&dit){

        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        for(int i=0;i<dit.size();i++){
             string a=dit[i];
            int len=a.length();
            for(int start=0;start+len<=n;start++){
                if(s.substr(start,len)==a){
                    dp[start][start+len-1]=1;
                }
            }
        }
        return help(s,0,n-1,dp);
    }
};
