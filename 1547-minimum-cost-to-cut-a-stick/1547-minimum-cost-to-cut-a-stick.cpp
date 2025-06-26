// class Solution {
// public:              mleeeeeeeeeeeeeeee 
//     int help(vector<int>&cuts,int lower,int upper,vector<vector<int>>&dp){
//         if(lower>=upper)return 0;

//         if(dp[lower][upper]!=-1)return dp[lower][upper];

//         int mini=INT_MAX;
        
//         for(int i=0;i<cuts.size();i++){
//             int val=cuts[i];
//             if(val>lower&&val<upper){
//                     int left=help(cuts,lower,val,dp);
//                 int right=help(cuts,val,upper,dp);
//                  int total=(upper-lower)+left+right;
//                 mini=min(mini,total);
//             }
//         }
        
//         if(mini==INT_MAX)mini=0;

//         return dp[lower][upper]=mini;
//     }

//     int minCost(int n,vector<int>&cuts){
//         cuts.push_back(0);
//         cuts.push_back(n);
//         sort(cuts.begin(),cuts.end());
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         return help(cuts,0,n,dp);
//     }
// };
class Solution {
public:
    int help(vector<int>&cuts,int lower,int upper,vector<vector<int>>&dp){
        if(lower+1==upper)return 0;
        if(dp[lower][upper]!=-1)return dp[lower][upper];
        int mini=INT_MAX;
        for(int i=lower+1;i<upper;i++){
            int left=help(cuts,lower,i,dp);
         int right=help(cuts,i,upper,dp);
            int total=cuts[upper]-cuts[lower]+left+right;
          mini=min(mini,total);
        }
        return dp[lower][upper]=mini;
    }

    int minCost(int n,vector<int>&cuts){
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int sz=cuts.size();
        vector<vector<int>>dp(sz,vector<int>(sz,-1));
        return help(cuts,0,sz-1,dp);
    }
};
