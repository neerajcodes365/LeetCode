class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int>right(n);
        int maxi=INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,nums[i]);
            right[i]=maxi;
        }
        int l=0,r=0;
        int ans=0;
        while(r<n){
            while(l<n && nums[l]>right[r]) l++;
            ans=max(ans,r-l+1);
            r++;
        }
     

        return ans-1;
    }
};