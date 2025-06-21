class Solution {
public:
    int solve(int i, int t, int holding, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        if (i == prices.size() || t == 0)
            return 0;

        if (dp[i][t][holding] != -1)
            return dp[i][t][holding];

        int skip = solve(i + 1, t, holding, prices, dp);
        int act;
        if (holding) {

            act = prices[i] + solve(i + 1, t - 1, 0, prices, dp);
        } else {
            
            act = -prices[i] + solve(i + 1, t, 1, prices, dp);
        }

        return dp[i][t][holding] = max(skip, act);
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return solve(0, k, 0, prices, dp); 
    }
};
