class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0)nums[i]=-1;
        }
        int sum=0;
        

        map<int,int>mp;//sum,index,
        // mp[0]=1;
        int maxi=0;
        mp[0] = -1;
        int k=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.count(sum)){
                maxi=max(maxi,i-mp[sum]);
            }else{
                mp[sum]=i;
            }
        }

        // for(int i=0;i<n;i++){
        //         sum+=nums[i];
        //         if(!mp.count(sum)) mp[sum]=i;
        //         int crtsum=sum;
        //         int need=sum;
        //         if(crtsum==0){
        //             maxi=max(maxi,i);
        //         }
        //         else if(mp.count(need)){
        //             maxi=max(maxi,i-mp[need]);
        //         }
        // }
        return maxi;
    }
};