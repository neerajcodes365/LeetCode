class Solution {
public:
    // help(vector<int>&nums)
    long long maximumMedianSum(vector<int>& nums) {
        // help(nums,0,)
        long long ans=0;
        sort(nums.begin(),nums.end(),greater<int>());
        int n=nums.size();
        int a=0;
        for(int i=1;a<n/3;i+=2){
            a++;
            ans+=nums[i];
        }
    return ans;
    }
};