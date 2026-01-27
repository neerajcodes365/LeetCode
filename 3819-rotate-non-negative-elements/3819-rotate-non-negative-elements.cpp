class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        // vector<int>arr(n,INT_MAX);
        int help=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]>=0)help++;
        }
         if (help == 0) return nums;   
  k = k % help;
        vector<int>ans(help,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
            //    int index=cnt-k<0?cnt-k+help:cnt-k;
            int index = (cnt - k + help) % help;
                ans[index]=nums[i];
                cnt++;
            }
        }

        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                nums[i]=ans[j];
                j++;
            }
        }
        return nums;

    }
};