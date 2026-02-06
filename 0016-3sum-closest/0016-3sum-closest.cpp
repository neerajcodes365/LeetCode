class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
            int mini=INT_MAX;
            int ans=-1;
        for(int i=0;i<n;i++){
            int n1=nums[i];
            int n2=0;
            int n3=0;
            int j=i+1;
            int k=n-1;
            while(j<k){
                n2=nums[j];
                n3=nums[k];
                int sum=n1+n2+n3;
                int total=abs(target-sum);
                if(total<mini){
                    mini=abs(target-sum);
                    ans=sum;
                }
                 if(sum>target) k--;
                else j++;
            }
        }
        return ans;
    }
};