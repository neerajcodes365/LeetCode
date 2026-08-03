class Solution {
public:
    int help(int i,vector<int>&dp){
        if(i==0)return 1;
        if(i<0)return 0;
        // return 2+help(i-1)+help(i-2);
        if(dp[i]!=-1)return dp[i];
        int onestep=help(i-1,dp);
        int twostep=help(i-2,dp);
        return dp[i]=onestep+twostep;

    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
       return help(n,dp) ;
    }
};