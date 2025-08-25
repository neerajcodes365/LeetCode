class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

        int n=mat.size();
        int m=mat[0].size();

        int total=m+n-1;

        vector<pair<int,int>>help;

        for(int i=m-1;i>=0;i--){
            help.push_back({0,i});
            cout<<"this is index pushing"<<" 0 -"<<i<<endl;
        }

        for(int j=1;j<n;j++){
            help.push_back({j,0});
            cout<<"this is index pushing"<<j<<" -"<<0<<endl;
        }

        int i=0;
        while(i<total){
            auto[a,b]=help[i];
            int row=a,col=b;

            cout<<" a- "<<a<<" b- "<<b<<endl;

            vector<int>helpii;

            while(a<n && b<m){
                helpii.push_back(mat[a][b]);
                cout<<"this is the value "<<mat[a][b]<<endl;
                a++; 
                b++;
            }
            sort(helpii.begin(),helpii.end());
            // for(auto it:helpii){
            //     ans.push_back(it);
            // }
            int j=0;
            a=row,b=col;
            while(a<n && b<m){
                cout<<" inserted value "<<mat[a][b]<<endl;

                mat[a++][b++]=helpii[j++];
            }

            i++;
        }
        return mat;
    }
};