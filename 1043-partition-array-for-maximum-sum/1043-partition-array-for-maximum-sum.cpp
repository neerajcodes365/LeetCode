class Solution {
public:
    int n, k;
    vector<int> dp;

    int solve(int i, vector<int>& arr) {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int maxInPartition = 0, maxSum = 0;
        for(int j = i; j < min(i + k, n); j++) {
            maxInPartition = max(maxInPartition, arr[j]);
            int len = j - i + 1;
            maxSum = max(maxSum, maxInPartition * len + solve(j + 1, arr));
        }
        return dp[i] = maxSum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int K) {
        n = arr.size();
        k = K;
        dp.assign(n, -1);//matte satha dp declare aki reference nte pakaram(malayalam)
        return solve(0, arr);
    }
};
