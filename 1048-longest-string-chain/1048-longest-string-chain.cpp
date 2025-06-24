class Solution {
public:
     bool fn(string& longer, string& shorter) {
        if(longer.size()!=shorter.size()+1) return false;

        int i=0,j=0;

        while (i<longer.size()) {
            if (j<shorter.size()&&longer[i]==shorter[j]){
                i++;
                j++;
            }else i++;
        }
        return j==shorter.size();
    }
    static bool comparebylength(const string& a, const string& b) {
        return a.size() < b.size();}

    int longestStrChain(vector<string>& words) {
        // sort(words.begin(),words.end());
        sort(words.begin(), words.end(), comparebylength);
        int n=words.size();
        vector<int> dp(n,1);
        int maxans=1;
        for(int i=1;i<n;i++){
        int maxi=1;
            for(int j=0;j<i;j++){
                if(fn(words[i],words[j]) && dp[j]+1>maxi){
                    maxi=dp[j]+1;
                    dp[i]=maxi;
                }
                maxans=max(maxans,dp[i]);
            }
        }
        return maxans;
    }
};