class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
        vector<int>lps(n,0);
        int j=0;
        int maxi=0;
        int i=1;
        while(i<n){
            if(s[i]==s[j]){
                j++;
                lps[i]=j;
                maxi=max(lps[i],maxi);
                i++;
            }else{
                if(j!=0){
                    j=lps[j-1];
                }else{
                    lps[i++]=0;
                }
            }
        }
return maxi==0?"":s.substr(0,maxi);
    }
};