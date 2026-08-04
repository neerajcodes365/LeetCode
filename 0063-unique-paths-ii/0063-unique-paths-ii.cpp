class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++){//rows
            if(g[i][0]==1){
                while(i<n){
                dp[i][0]=0;
                i++;
                }
            }else dp[i][0]=1;
        }

        for(int i=0;i<m;i++){//col
            if(g[0][i]==1){
                while(i<m){
                dp[0][i]=0;
                i++;
                }
            }else dp[0][i]=1;
        }   

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(g[i][j]==1)dp[i][j]=0;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }     
        return dp[n-1][m-1];

    }
};