class Solution {
public:
    int help(vector<int>&coins,int index,int amount,int sum,vector<vector<int>>&dp){
        if(index<0 || sum>amount)return INT_MAX;
        if(sum==amount) return 0;
        if(dp[index][sum]!=-1)return dp[index][sum];
        // int picknext =help(coins,index-1,amount,sum+coins[index],ans+1,dp);
        int picksame=help(coins,index,amount,sum+coins[index],dp);
        if(picksame!=INT_MAX) picksame++;
        int skip=help(coins,index-1,amount,sum,dp);
        // if(skip!=INT_MAX) skip++;
        // return dp[index][sum]=min({picknext,picksame,skip});
        return dp[index][sum]=min(picksame,skip);

    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int a= help(coins,coins.size()-1,amount,0,dp);
        return a==INT_MAX?-1:a;
    }
};