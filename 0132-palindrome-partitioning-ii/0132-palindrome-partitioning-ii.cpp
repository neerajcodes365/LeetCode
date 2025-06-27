class Solution {
public:
    bool ispalindrome(string& str, int start, int end) {
        while(start<end){
            if(str[start]!=str[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    int solve(const string& str, int i, int j, vector<vector<int>>& dp) {
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        // if(isPalindrome(str,i,j)) return dp[i][j]=0;

        int mini=INT_MAX;
        for(int k=i;k<=j;k++){
            // if(isPalindrome(str,i,k)){
                if(dp[i][k]==0){
                int cut=1+solve(str,k+1,j,dp);
                 mini=min(cut,mini);
            }
        }
        return dp[i][j]=mini;
    }

    int minCut(string str) {
        int n=str.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            dp[i][i]=0;
            for(int j=i+1;j<n;j++){
                if(ispalindrome(str,i,j)){
                    dp[i][j]=0;
                }
            }
        }
        return solve(str,0,n-1,dp);
    }
};
