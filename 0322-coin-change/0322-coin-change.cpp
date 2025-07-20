class Solution {
public:
  unsigned  long long int help(vector<int>&coins,int amount,long long int  count,int idex,vector<vector<long long>>&dp){

        if(count==amount) return 0;
        if(count>amount || idex>=coins.size()) return LLONG_MAX;
            if(dp[count][idex]!=-1)return dp[count][idex];



        // int pick=
        unsigned long long int pick=help(coins,amount,count+coins[idex],idex,dp);
        if(pick!=LLONG_MAX) pick+=1;

        // int notpick;
       unsigned  long long int notpick=help(coins,amount,count,idex+1,dp);

        return dp[count][idex]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        // mini=-1;
vector<vector<long long>> dp(amount + 1, vector<long long>(coins.size(), -1));
      unsigned long long int  mini=help(coins,amount,0,0,dp);
        return mini==LLONG_MAX?-1:mini;
    }
};