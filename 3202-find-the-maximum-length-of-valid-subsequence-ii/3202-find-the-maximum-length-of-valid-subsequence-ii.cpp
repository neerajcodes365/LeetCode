class Solution {
public:
/*
int n;
    int help(vector<int>&nums,int k,int index,int prv,int kval){
        if(index>=n)return 0;
        int a=0;
        if(kval!=-1 && (nums[prv]+nums[index]) % k==kval){
            //pick possible
            // a++;
             a=1+help(nums,k,index+1,index,kval);
        }
        int b=0;
         if(kval != -1) {
            b = help(nums, k, index + 1, prv, kval);
        }
        for(int i = 0; i < k; i++) {
            if((nums[prv] + nums[index]) % k == i) {
                b = max(b, 1 + help(nums, k, index + 1, index, i));
            }
        }
        return max(a,b);
    }
    int maximumLength(vector<int>& nums, int k) {
        n=nums.size();
        if(n<=2)return n;
        int prv=0;
        // int kval=(nums[1]+nums[0])%k;
       return 1+help(nums,k,1,prv,-1);//1 for the 

       */
    int n;
    int maximumLength(vector<int>& nums, int k) {
        n=nums.size();
        if(n<=1)return n;
        vector<vector<int>>dp(k,vector<int>(n,1));
        int ans=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int modval=(nums[i]+nums[j])%k;
                dp[modval][i]=max(dp[modval][i],dp[modval][j]+1);
                ans=max(ans,dp[modval][i]);
            }
        }
    return ans;

    }
};