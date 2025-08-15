class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& g) {
        int n=g.size();
        int m=g[0].size();

        vector<vector<char>>ans(m,vector<char>(n,'.'));

        for(int i=0;i<n;i++){
            int count=0;
            int j=0;
            while(j<m){
                if(g[i][j]=='#') {
                    count++;
                    j++;
                }
                else if( g[i][j]=='*'){
                    int newcol=n-1-i;
                    int newrow=j;
                    ans[newrow][newcol]='*';
                    newrow--;
                    while(count!=0){
                        ans[newrow][newcol]='#';
                        count--;
                        newrow--;
                    }
                    j++;
                }
                else{
                    j++;
                }
            }
            int newcol = n - 1 - i;
            int rowi = m - 1;
            while(count != 0) {
                ans[rowi][newcol] = '#';
                count--;
                rowi--;
            }

        }

return ans;
    
    }
};