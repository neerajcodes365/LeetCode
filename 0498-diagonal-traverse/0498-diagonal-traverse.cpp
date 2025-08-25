class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int flag=0;
        vector<int>ans;
        int n=mat.size();
        int m=mat[0].size();

        int total=m+n-1;

        vector<pair<int,int>>help;

        for(int i=0;i<m;i++){
            help.push_back({0,i});
            cout<<"this is index pushing"<<" 0 -"<<i<<endl;
        }

        for(int j=1;j<n;j++){
            help.push_back({j,m-1});
            cout<<"this is index pushing"<<j<<" -"<<m-1<<endl;
        }
        int i=0;

        while(i<total){
            auto[a,b]=help[i];
            cout<<" a- "<<a<<" b- "<<b<<endl;
            vector<int>helpii;

            while(a<n && b>=0){
                helpii.push_back(mat[a][b]);
                cout<<"this is the value "<<mat[a][b]<<endl;
                a++; 
                b--;
            }

            // flag=!flag;
            

            if(flag==0){
                reverse(helpii.begin(),helpii.end());
            }
            flag=(flag==0)?1:0;

            for(auto it:helpii){
                ans.push_back(it);
            }

            i++;
        }
        return ans;

    }
};