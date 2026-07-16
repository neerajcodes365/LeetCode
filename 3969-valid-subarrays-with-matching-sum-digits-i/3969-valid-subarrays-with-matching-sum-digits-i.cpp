class Solution {
public:

    int countValidSubarrays(vector<int>& nums, int x) {
        vector<long long>prefix(nums.size()+1,0);
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=nums[i];
            prefix[i+1]=ans;
        }
        int n=nums.size();

int cnt=0;
// int total=prefix[n-1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                long long no=prefix[j]-prefix[i];
                // cout<<no<<endl;
                if(no%10==x){
                    while(no>=10){
                        no=no/10;
                    }
                    if(no==x) {
                        cnt++;
                        // cout<<"i"<<i<<"J"<<j<<endl;
                        }
                }
            }
        }
        // for(auto it:nums){
        //     int no=it;
        //     if(no%10==x){
        //             while(no>=10){
        //                 no=no/10;
        //             }
        //             if(no==x) {
        //                 cnt++;
        //                 // cout<<"i"<<i<<"J"<<j<<endl;
        //                 }
        //         }
        // }
        return cnt;

    }
};