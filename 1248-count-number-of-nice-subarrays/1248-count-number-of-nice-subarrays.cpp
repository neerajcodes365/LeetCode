class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int,int>mp;//oddnumfeq,index;
        int feq=0;
        int n=nums.size();
        int ans=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            // if(nums[i]&1) {
                if(nums[i]&1) feq++;
            // }
            int crtfeq=feq;
            int need=feq-k;
            if(mp.count(need)){
                ans+=mp[need];
            }
                mp[feq]++;


        }
        return ans;
    }
};