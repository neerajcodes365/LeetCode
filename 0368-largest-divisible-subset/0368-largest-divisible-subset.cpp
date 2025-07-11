class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>hash(nums.size());
        vector<int>dp(nums.size(),1);
        sort(nums.begin(),nums.end());
        dp[0]=1;
        hash[0]=0;
        int maxdp=1;
        int maxindex=0;
        
         for(int i=1;i<nums.size();i++){
            hash[i]=i;
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0 && dp[j]+1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            // dp[i]=num+1;
            // hash[i]=index;
            if(dp[i]>maxdp){
                    maxdp=dp[i];
                    maxindex=i;
            }

        }
    
    vector<int>ans;
    //     ans.push_back(nums[maxindex]);
    //     maxindex=hash[maxindex];
    // }
     while(hash[maxindex] != maxindex) {
            ans.push_back(nums[maxindex]);
            maxindex = hash[maxindex];
        }
        ans.push_back(nums[maxindex]);
    reverse(ans.begin(),ans.end());
    return ans;
    }

};
/*
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>hash(nums.size());
        vector<int>dp(nums.size(),1);
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++) hash[i] = i;
        
        int maxdp = 1;
        int maxindex = 0;
        
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0 && dp[j]+1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[i]>maxdp){
                maxdp = dp[i];
                maxindex = i;
            }
        }

        vector<int>ans;
        while(hash[maxindex] != maxindex){
            ans.push_back(nums[maxindex]);
            maxindex = hash[maxindex];
        }
        ans.push_back(nums[maxindex]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};*/