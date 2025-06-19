class Solution {
public:
int lcsubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp (n+1, vector<int> (m+1, 0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
    int minDistance(string wi, string wii) {
        int num=lcsubsequence(wi,wii);
        return wi.length()-num +wii.length()-num;
        // return max(wi.length(),wii.length())-num;
    }
};