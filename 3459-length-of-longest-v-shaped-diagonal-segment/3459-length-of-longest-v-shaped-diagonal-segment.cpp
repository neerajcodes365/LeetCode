class Solution {
public:
    vector<vector<int>> dir={{-1,-1},{-1,1},{1,1},{1,-1}};
    vector<int> nxt={2,2,0};
    int dp[501][501][4][3][2];

    int help(int i,int j,vector<vector<int>>&g,int d,int exp,int t){
        if(i<0||j<0||i>=g.size()||j>=g[0].size()||g[i][j]!=exp) return 0;
        if(dp[i][j][d][exp][t]!=-1) return dp[i][j][d][exp][t];
        int ans=1+help(i+dir[d][0],j+dir[d][1],g,d,nxt[exp],t);
        if(t>0){
            int nd=(d+1)%4;
            ans=max(ans,1+help(i+dir[nd][0],j+dir[nd][1],g,nd,nxt[exp],t-1));
        }
        return dp[i][j][d][exp][t]=ans;
    }

    int lenOfVDiagonal(vector<vector<int>>&g){
        int n=g.size(),m=g[0].size(),res=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1){
                    for(int d=0;d<4;d++){
                        res=max(res,help(i,j,g,d,1,1));
                    }
                }
            }
        }
        return res;
    }
};
