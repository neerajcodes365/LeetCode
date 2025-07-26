class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        int mul=1;
        int i=0,j=0;
        int n=nums.size();
        if(k==0)return ans;
        while(j<n){
            mul*=nums[j];
            if(mul>=k) {
                while(mul>=k && i<=j){
                    mul=mul/nums[i];
                    i++;
                }
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};