class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        int j=n-1;
        if(n==1)return 0;
        while(i<=j){
            int mid=(i+j)>>1;
            if (mid == 0) {
                if (nums[mid] > nums[mid + 1]) return mid;
                else i = mid + 1;
            }
            else if (mid == n - 1) {
                if (nums[mid] > nums[mid - 1]) return mid;
                else j = mid - 1;
            }
            else if( nums[mid]>nums[mid-1]&& nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]<nums[mid+1]){
                    i=mid+1;
                }
            else{
                    j=mid-1;
                }
        }
        return -1;
    }
};