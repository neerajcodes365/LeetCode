class Solution {
public:
    int longestBalanced(vector<int>& nums) {

int n=nums.size();
int even=0,odd=0;
int ans=INT_MIN;
map<int,int>mp;//eventotalcountdiff,index;
 mp[0] = -1;

        for(int i=0;i<n;i++){
            if(nums[i]%2==0)even++;
            else odd++;
            int diff=even-odd;
            if(mp.count(diff)){
                ans=max(ans,i-mp[(diff)]);
            }
            else mp[diff]=i;
        }
        return ans;
// int ans=INT_MIN;
// map<int,int>emp;//evencount,index
// map<int,int>omp;//oddcount,index
// int flag;
//     for(int i=0;i<n;i++)
//         if(nums[i]%2==0){
//             flag=0;
//             even++;}
//         else {
//             odd++;
//             flag=1;}
//         if(flag!){
//             int diff=
        


    }
};