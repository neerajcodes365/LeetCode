class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a=nums[i];
                int b=nums[j];
                int sum=a+b;
                // auto it=nums.upper_bound(sum);
                auto it=lower_bound(nums.begin()+j+1,nums.end(),sum);
                ans+=(it-(nums.begin()+j+1));
            }
        }
        return ans;
        
    }
};