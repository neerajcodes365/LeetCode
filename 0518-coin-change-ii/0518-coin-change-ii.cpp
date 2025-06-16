class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<unsigned long long>>dp(n+1,vector<unsigned long long>(amount+1,0));
        dp[0][0] = 1;

        for(int i=1;i<=n;i++){
            for(int j=0;j<amount+1;j++){
       unsigned  long long exclude=dp[i-1][j];
     unsigned  long long include=0;
                if(coins[i-1]<=j) include=dp[i][j-coins[i-1]];
                dp[i][j]=exclude+include;
            }
        }
return dp[n][amount];
    }
};