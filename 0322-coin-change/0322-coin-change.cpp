class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        long long maxi = (long long)INT_MAX + 1;
        vector<vector<long long>> dp(n + 1, vector<long long>(amount + 1, maxi));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0; 
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                long long exclude = dp[i - 1][j];
                long long include = maxi;
                if (coins[i - 1] <= j) {
                    include = dp[i][j - coins[i - 1]] + 1;
                }
                dp[i][j] = min(include, exclude);
            }
        }

        return dp[n][amount] >= maxi ? -1 : (int)dp[n][amount];
    }
};
