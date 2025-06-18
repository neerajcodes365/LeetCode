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
    int longestPalindromeSubseq(string s1) {
        // string s2=string(s1.end(),s1.begin());
        string s2=string(s1.rbegin(),s1.rend());
        return lcsubsequence(s1,s2);
        
    }
};