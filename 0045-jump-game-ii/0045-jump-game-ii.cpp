class Solution {
public:
    int jump(vector<int>& nums) {
        int left=0;
        int right=0;
        int ans=0;
        int n=nums.size();
        if(n==1)return 0;

int far=0;
        while(right<n-1){

            for(int i=left;i<=right;i++){
                far=max(far,nums[i]+i);
            }
            left=right+1;
            right=far;
            ans++;
        }
        return ans;
    }
};