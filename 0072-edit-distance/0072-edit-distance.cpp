class Solution {
public:
    int minDistance(string wi, string ws) {
        int n=wi.length();
        int m=ws.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
{
    dp[i][0]=i;
}
for(int i=0;i<=m;i++){
    dp[0][i]=i;
}

for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(wi[i-1]==ws[j-1]) dp[i][j]=dp[i-1][j-1];
        else{
            dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
        }
    }
}
return dp[n][m];


    }
};