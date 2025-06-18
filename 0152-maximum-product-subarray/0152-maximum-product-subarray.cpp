class Solution {
public:
    int maxProduct(vector<int>& nums) {
        typedef vector<int> sasi;
        sasi dp(nums.size());
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            int back=dp[i-1];
            int current=nums[i];
            int multi=nums[i-1]*current;
            int maxi=max(multi,current);
            int finali=max(maxi,back);
            dp[i]=finali;
        }
        return dp[nums.size()-1];
    }
};