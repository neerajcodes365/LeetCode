class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,0);
        dp[0]=1;
        int ans=1;
        for(int i=1;i<n;i++){
            int j=i-1;
            int maxi=0;
            while(j>=0){
                if(arr[j]<arr[i]) maxi=max(dp[j],maxi);
                j--;
            }
            dp[i]=maxi+1;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};