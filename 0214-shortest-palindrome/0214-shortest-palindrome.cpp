class Solution {
public:
    string shortestPalindrome(string s) {
        string revs=s;
        int ssize=s.length();
        reverse(revs.begin(),revs.end());
        string ans=s+'*'+revs;//* to start checking from there other there is a chance for wrong answer 
        int size=ans.size();
        vector<int>lps(size);
        int j=0;//len
        int i=1;
        while(i<size){
            if(ans[i]==ans[j]){
                j++;
                lps[i]=j;
                i++;
            }
            else{
                if(j!=0) j=lps[j-1];
                else lps[i++] =0;
            }
        }
        int len=lps[size-1];
        // len=ssize-len;
        string start=s.substr(len);
        reverse(start.begin(),start.end());
        return start+s;
    }
};