class Solution {
public:
    int maxi;
    // max=-1;
    void backtrack(vector<int>&nums,int index,int sum){
        if(sum>maxi)maxi=sum;
        if(index>=nums.size()) return;

        for(int i=index;i<nums.size();i++){
            // if(index==i-1) continue;
            sum+=nums[i];
            backtrack(nums,i+2,sum);
            sum-=nums[i];
        }
    }
    int rob(vector<int>& nums) {
        int sum=0;
        maxi=-1;
        backtrack(nums,0,sum);
        return maxi;
    }
};