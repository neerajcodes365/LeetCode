class Solution {
public:
    int possibleStringCount(string w) {
        int ans=1;
        int n=w.size();
        for(int i=0;i<n;i++){
            if(i+1<n && w[i]==w[i+1]) ans++;
        }
        return ans;
    }
};