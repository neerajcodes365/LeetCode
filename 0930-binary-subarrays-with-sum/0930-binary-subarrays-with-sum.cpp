class Solution {
public:
    int help(vector<int>&nums,int goal){
        // int sum+=nums[i]
        int i=0;
        int j=0;
        int sum=0;
        int ans=0;
        int n=nums.size();

        while(j<n){
            sum+=nums[j];
            while(i<=j&&sum>goal ){
                sum-=nums[i];
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // int ans=0;
        // int sum=0;
        // int i=0;
        // int j=0;
        // int n=nums.size();
        // while(j<n){
        //     sum+=nums[j];
        //         while(i<n && sum>goal){
        //             sum-=nums[i];
        //             i++;
        //         }

        //     if(sum==goal){
        //         int temp=i;
        //         // temp++;
        //         int count=0;
        //         while(temp<=j && nums[temp]==0){
        //             // ans++;
        //             count++;
        //             temp++;
        //         }
        //         // ans++;
        //         ans+=(count+1);
        //     }
        //     j++;
        // }
        // return ans;
        return help(nums,goal)-help(nums,goal-1);
    }
};