class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int maxi=INT_MIN;
        // if(k==1 && nums.size()==1)return -1;
        int n=nums.size();
        if(n==1){
            if(k%2==0)return nums[0];
            else return -1;
        }
        for(int i=0;i<k+1;i++){
            if(i==k-1) continue;
            if(i<n) maxi=max(maxi,nums[i]);
        }
        return maxi;
    }
};