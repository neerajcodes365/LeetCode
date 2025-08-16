class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>ycount(3,0), othercount(3,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int val=grid[i][j];

                if( (i==j && i<=n/2) || (i+j==n-1 && i<=n/2) || (j==n/2 && i>=n/2) ){
                    ycount[val]++;
                }
                else{
                    othercount[val]++;
                }
            }
        }

        int ytotal=ycount[0]+ycount[1]+ycount[2];
        int othertotal=othercount[0]+othercount[1]+othercount[2];
        int ans=INT_MAX;

        for(int c1=0;c1<3;c1++){
            for(int c2=0;c2<3;c2++){
                if(c1==c2) continue;
                int changes=(ytotal-ycount[c1])+(othertotal-othercount[c2]);
                ans=min(ans,changes);
            }
        }
        return ans;
    }
};
