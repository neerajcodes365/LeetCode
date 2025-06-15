class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }

        if ((sum + target) % 2 != 0 || abs(target) > sum) return 0;

        int p = (sum + target) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(p + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= p; j++) {
                if (nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][p];
    }
};
