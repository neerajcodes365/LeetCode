class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));

        for (int j = 0; j <= m; ++j) dp[0][j] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (t[i-1] == s[j-1])
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }

        return dp[n][m];
    }
};
