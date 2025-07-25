// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         // map<int,int>mp;//sum,index
//         int sum=0;
//         int n=nums.size();

//         vector<int>prefix(n+1,0);

//         for(int i=0;i<n;i++){
//             prefix[i]=sum;
//             sum+=nums[i];
//         }

//        prefix[n]=sum;
//         int ans=0;
//         for(int i=0;i<=n;i++){
//             for(int j=i+1;j<=n;j++){
//                 if((prefix[j]-prefix[i])==k) ans++;
//             }
//         }
//         return ans;
//     }
// };


class Solution {

public:
int ans;
int n;

    void help(vector<int>& nums, int k, int index, int sum) {
        if (index >= n) return;

        sum += nums[index];
        if (sum == k) ans++;

        help(nums, k, index + 1, sum); 
    }

    int subarraySum(vector<int>& nums, int k) {
        ans = 0;
        n = nums.size();

        for (int i = 0; i < n; i++) {
            help(nums, k, i, 0);  
        }

        return ans;
    }
};