class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        long long ans=0;
        int n=mat.size();
        int negcount=0;
        int smallneg=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]<0){
                    negcount++;
                }
                smallneg=min(smallneg,abs(mat[i][j]));
                ans+=abs(mat[i][j]);
                cout<<ans<<endl;
            }
        }
        cout<<smallneg<<"smallneg"<<endl;
        cout<<negcount<<"negcount"<<endl;
        if(negcount%2==0) return ans;
        else return ans-2*smallneg;
    }
};