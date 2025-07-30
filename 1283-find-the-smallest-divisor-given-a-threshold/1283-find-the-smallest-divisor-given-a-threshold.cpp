class Solution {
public:
     bool help(vector<int>&nums, int threshold, int divisor) {
        int total=0;
        for (int num:nums) {
            // total+=(num+divisor-1)/divisor;  
        }
        return total<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        // int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());

        // for(int i=0;i<n)
        int low=1;
        int high=maxi;
        int ans=maxi;

        while(low<=high){
            int mid=low+(high-low)/2;
            bool hp=help(nums,threshold,mid);
            if(hp){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
    return ans;
    }
};