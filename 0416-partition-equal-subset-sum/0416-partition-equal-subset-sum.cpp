class Solution {
public:
    bool help(vector<int>&nums,int index,int sum,int target,vector<vector<int>>&dp){
        
        if(sum==target) return true;
        if(index<0||sum>target) return false;
        if(dp[index][sum]!=-1) return dp[index][sum]; 
       
        bool pick =help(nums,index-1,sum+nums[index],target,dp);
        bool unpick =help(nums,index-1,sum,target,dp);
       
        return dp[index][sum]=pick||unpick;
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums)sum+=it;
        int target=sum/2;

        if(sum%2==1)return false;
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));

        return help(nums,nums.size()-1,0,target,dp);
    }
};