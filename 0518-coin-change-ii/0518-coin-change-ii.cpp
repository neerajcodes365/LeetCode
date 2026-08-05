class Solution {
public:
    int help(int amount,vector<int>&coins,int index,int sum,vector<vector<int>>&dp){
        if(sum==amount)return 1;
        if(sum>amount || index<0)return 0;
        if(dp[index][sum]!=-1) return dp[index][sum];
        int notskip=help(amount,coins,index,sum+coins[index],dp);
        int skip=help(amount,coins,index-1,sum,dp);
        return dp[index][sum]=skip+notskip;
    }

    int change(int amount, vector<int>& coins) {
        int sum=0;
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
       return help(amount,coins,coins.size()-1,sum,dp);
    }
};