class Solution {
public:
    int n;
    int m;
    void dfs(int row,int col,vector<vector<int>>&board,vector<vector<int>>&visited ){
        visited[row][col]=1;
        int rowi[]={0,0,-1,1};
        int coli[]={1,-1,0,0};
        for(int i=0;i<4;i++){
            int nrow=row+rowi[i];
            int ncol=col+coli[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]==1 && visited[nrow][ncol] == 0){
                dfs(nrow,ncol,board,visited);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid.size();
         int count =0;
        vector<vector<int>>visited(n,vector<int>(m,0));
         for(int i=0;i<n;i++){
            if(grid[i][0]==1 && visited[i][0]==0) dfs(i,0,grid,visited);
            if(grid[i][m-1]==1 &&visited[i][m-1]==0) dfs(i,m-1,grid,visited);
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && visited[0][j]==0) dfs(0,j,grid,visited);
            if(grid[n-1][j]==1 && visited[n-1][j]==0) dfs(n-1,j,grid,visited);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]==0) count++;
            }
        }
        return count ;
    }
};