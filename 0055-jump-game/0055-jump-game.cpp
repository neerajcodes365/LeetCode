class Solution {
public:
int n;
    bool help(vector<int>& nums,int i,vector<int>&dp){
        // if(i>=n) return true;
        if (i >= n - 1) return true;
        if(dp[i]!=-1) return dp[i];
        for(int k=1;k<=nums[i];k++){
           bool dup=help(nums,i+k,dp);
            if(dup) return dp[i]=dup;
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        // ans=false;
        n=nums.size();
        if (n == 1) return true;
        // if(nums[0]=0 && n==1) return true;
        vector<int>dp(n,-1);
       return  help(nums,0,dp);
    }
};