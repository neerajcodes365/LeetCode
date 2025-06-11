class Solution {
public:
    int minPathSum(vector<vector<int>>& mat) {
        int n=mat.size();//NxM
        int m=mat[0].size();//col
        vector<vector<int>>dp(n,vector<int>(m));
        dp[0][0]=mat[0][0];
        for(int i=1;i<n;i++){
            dp[i][0]=dp[i-1][0]+mat[i][0];
        }
        for(int i=1;i<m;i++){
            dp[0][i]=dp[0][i-1]+mat[0][i];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=mat[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};