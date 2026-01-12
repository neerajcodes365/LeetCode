class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int ans=0;
        int n=p.size();
        for(int i=0;i<n-1;i++){
            int a=p[i][0];
            int b=p[i][1];
            int an=p[i+1][0];
            int bn=p[i+1][1];
            ans+=max( abs(an-a), abs(bn-b) );
            // cout<<an-a<<endl;
            // cout<<ans<<endl;
        }
        return ans;
    }
};