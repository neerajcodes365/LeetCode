class Solution {
public:
    int help(vector<int>nums,int i,int n,vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int skip=help(nums,i+1,n,dp);
        int pick=nums[i]+help(nums,i+2,n,dp);
        return dp[i]=max(skip,pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return help(nums,0,n,dp);
    }
};