class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        dp[0][0] = 1;
for(int i=0;i<n+1;i++){
    dp[i][0]=1;
}
        for(int i=1;i<=n;i++){
            for(int j=1;j<amount+1;j++){
                int exclude=dp[i-1][j];
                int include=0;
                if(coins[i-1]<=j) include=dp[i][j-coins[i-1]];
                dp[i][j]=exclude+include;
            }
        }
return dp[n][amount];
    }
};