class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int i=0;
        int j=0;
        int n=nums.size();
        int count=0;
        while(j<n){
            if(nums[j]==0)count++;
            // if()
            // if(nums[j]==1) j++;
            if(count>k){
                // count=0;
                while(i<n && count>k){
                    if(nums[i]==0) count--;
                    i++;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};