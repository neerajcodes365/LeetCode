class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n=nums.size();
        vector<char>dup;
        for(auto it:nums){
            if(it<a)dup.push_back('l');
            else if(it>=a && it<=b) dup.push_back('m');
            else dup.push_back('r');
        }
        int cl=0,cm=0,cr=0;
        int ans=0;
        int const mod=1e9+7;

        for(auto it:dup){
            if(it=='m') {
                ans+=cr;
                // ans+=cl;
                cm++;
                ans=ans%mod;
                }
            else if(it=='l'){
                ans+=cm;
                ans=ans%mod;

                ans+=cr;
                ans=ans%mod;

                cl++;
            }else{
                cr++;
            }
        }
        return ans=ans%mod;
    }
};