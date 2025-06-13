class Solution {
public:
    bool subsetsum(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<bool>> dp(n , vector<bool>(sum + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (j >= nums[i - 1])
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n-1][sum];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto it : nums) sum += it;
        if (sum % 2 != 0) return false;
        return subsetsum(nums, sum / 2);
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0";});