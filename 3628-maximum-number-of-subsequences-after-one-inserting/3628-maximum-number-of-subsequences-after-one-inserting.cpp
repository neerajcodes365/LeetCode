class Solution {
public:
    long long numOfSubsequences(string s) {
        long long countl=0;
        long long countlc=0;
        long long countlct=0;

        for(auto i:s){
            if(i=='L'){
                countl++;
            }
            else if(i=='C'){
                countlc+=countl;
            }
            else if(i=='T'){
                countlct+=countlc;
            }
        }
        int n=s.size();
        vector<int>prefix(n+1,0);
        vector<int>suffix(n+1,0);

int ans=0;
        for(int i=1;i<n;i++){
            if(s[i]=='L'){ ans++;}
            prefix[i]=ans;
        }
ans=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='L'){ ans++;}
            prefix[i]=ans;
        }

        ans=0;
        for(int i=0;i<n;i++){
            int lbefore=prefix[i];
            int lafter=suffix[i];
            ans=max(ans,lafter*lbefore);
        }
        int extrat=countlc;
        int extral=0;
        int extrac=0;
    for(auto i:s){
        if(i=='C') extrac++;
        else if(i=='T') extral+=extrac;
    }
    // extral=
        return countlct+max({ans,extral,extrat});
    }
};