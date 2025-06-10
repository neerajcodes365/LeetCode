// class Solution {
// public:

//     int count;
//     void help(int n){
//         if(n==0){
//             count++;
//             return;
//         }
//         else if(n<0)return;
//          help(n-1) ;
//          help(n-2);
//          return;
//     }
//     int climbStairs(int n) {
//         count=0;
//         help(n);
//         return count;
        
//     }
// };
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }

        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};