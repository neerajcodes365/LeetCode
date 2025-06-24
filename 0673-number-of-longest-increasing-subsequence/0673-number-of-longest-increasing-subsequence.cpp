// class Solution {
// public:
//     int findNumberOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>dp(n,1);
//         int maxans=1;
//         for(int i=1;i<n;i++){
//         int maxi=1;
//             for(int j=0;j<i;j++){
//                 if( nums[i]>nums[j] && dp[j]+1>maxi){
//                     maxi=dp[j]+1;
//                     dp[i]=maxi;
//                 }
//                 maxans=max(maxans,dp[i]);
//             }
//         }
//         int ans=1;
        
//         // for(int i=0;i<n;i++){
//         //         int digit=1;
//         //         int i=0;
//         //     while(i<n){
//         //         int count=1;
//         //         while (i < n && dp[i] == digit){
//         //             count++;
//         //             i++;
//         //         }
//         //     ans*=count;
//         //     digit++;
//         // }
//         // int ans = 1;
//           int maxLen = *max_element(dp.begin(), dp.end());
// int digit = 1;
// int i = 0;
// while (digit <= maxLen) {
//     int count = 0;
//     for (int j = 0; j < n; ++j) {
//         if (dp[j] == digit) {
//             count++;
//         }
//     }
//     if (count > 0) ans *= count;
//     digit++;
// }



//         return ans;

//     }
// };
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        int maxans = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j]; 
                    } else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j]; 
                    }
                }
            }
            maxans = max(maxans, dp[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxans) {
                ans += count[i];
            }
        }

        return ans;
    }
};
