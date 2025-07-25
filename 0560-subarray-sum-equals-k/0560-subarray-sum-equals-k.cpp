class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // map<int,int>mp;//sum,index
        int sum=0;
        int n=nums.size();

        vector<int>prefix(n+1,0);

        for(int i=0;i<n;i++){
            prefix[i]=sum;
            sum+=nums[i];
        }

       prefix[n]=sum;
        int ans=0;
        for(int i=0;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if((prefix[j]-prefix[i])==k) ans++;
            }
        }
        return ans;
    }
};