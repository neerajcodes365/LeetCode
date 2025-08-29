class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();


        int total=m+n-1;

        vector<pair<int,int>>help;

        for(int i=0;i<n;i++){
            help.push_back({i,0});
            // cout<<"this is index pushing"<<i<<" 0 -"<<endl;
        }

        for(int j=1;j<m;j++){
            help.push_back({0,j});
            // cout<<"this is index pushing"<<" -"<<0<<j<<endl;
        }

        int i=0;

        while(i<total){
            auto[a,b]=help[i];
            int row=a,col=b;

            // cout<<" a- "<<a<<" b- "<<b<<endl;

            vector<int>helpii;

            while(a<n && b<m){
                helpii.push_back(mat[a][b]);
                // cout<<"this is the value "<<mat[a][b]<<endl;
                a++; 
                b++;
            }

            if(row>=0&& col==0) sort(helpii.begin(),helpii.end(),greater<int>());
            else sort(helpii.begin(),helpii.end());

            int j=0;
            a=row,b=col;
            while(a<n && b<m){

                cout<<" inserted value "<<helpii[j]<<endl;
                mat[a++][b++]=helpii[j++];
            }
            i++;
        }
        return mat;
    }
};