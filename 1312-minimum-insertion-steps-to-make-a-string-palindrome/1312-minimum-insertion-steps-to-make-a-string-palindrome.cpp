class Solution {
public:
    int lcsequence(string s,string snd){
        int n1=s.size();
        int n2=snd.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1]==snd[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
    int minInsertions(string s) {
        string snd=s;
        reverse(snd.begin(),snd.end());
        int num=lcsequence(s,snd);
        return s.size()-num;
    }
};