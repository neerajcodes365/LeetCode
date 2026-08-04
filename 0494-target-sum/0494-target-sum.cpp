class Solution {
public:
 long long help(vector<int>&nums,int index,int sum,int target,vector<vector<int>>&dp){
        
       if(index < 0) return sum == target ? 1 : 0;
        if(sum > target) return 0;
        if(dp[index][sum]!=-1) return dp[index][sum]; 
       
        long long pick =help(nums,index-1,sum+nums[index],target,dp);
        long long unpick =help(nums,index-1,sum,target,dp);
       
        return dp[index][sum]=pick+unpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto it:nums)sum+=it;
        if(target > sum || target < -sum) return 0;
        if((sum - target) % 2 != 0) return 0;  
        int ogitarget=(sum-target)/2;
        vector<vector<int>>dp(nums.size(),vector<int>(ogitarget+1,-1));
        return help(nums,nums.size()-1,0,ogitarget,dp);
    }
};