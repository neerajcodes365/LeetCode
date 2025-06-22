// class Solution {   cp3 solution 
// public:
//     int lengthOfLIS(vector<int>& arr) {
//         int n=arr.size();
//         vector<int>dp(n,0);
//         dp[0]=1;
//         int ans=1;
//         for(int i=1;i<n;i++){
//             int j=i-1;
//             int maxi=0;
//             while(j>=0){
//                 if(arr[j]<arr[i]) maxi=max(dp[j],maxi);
//                 j--;
//             }
//             dp[i]=maxi+1;
//             ans=max(ans,dp[i]);
//         }
//         return ans;
//     }
// };


class Solution {  //nlogn solution
public:
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp;
        dp.push_back(arr[0]);
        int j=0;
        for(int i=1;i<n;i++){
            if(arr[i]>dp.back()){
                dp.push_back(arr[i]);
            }
            else{
                auto index=lower_bound(dp.begin(),dp.end(),arr[i]);
                // dp[index]=arr[i];
                *index=arr[i];
            }

        }
        return dp.size();
    }};