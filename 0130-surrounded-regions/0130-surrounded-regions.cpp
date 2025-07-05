class Solution {
public:
    int n;
    int m;
    void dfs(int row,int col,vector<vector<char>>&board,vector<vector<int>>&visited ){
        visited[row][col]=1;
        int rowi[]={0,0,-1,1};
        int coli[]={1,-1,0,0};
        for(int i=0;i<4;i++){
            int nrow=row+rowi[i];
            int ncol=col+coli[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O' && visited[nrow][ncol] == 0){
                dfs(nrow,ncol,board,visited);
            }
        }
    }



    void solve(vector<vector<char>>& board) {
         n=board.size();
        m=board[0].size();
        // vector<vector<int>>mark(n,vector<int>(m,0));
        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && visited[i][0]==0) dfs(i,0,board,visited);
            if(board[i][m-1]=='O'&&visited[i][m-1]==0) dfs(i,m-1,board,visited);
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O'&&visited[0][j]==0) dfs(0,j,board,visited);
            if(board[n-1][j]=='O'&&visited[n-1][j]==0) dfs(n-1,j,board,visited);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && visited[i][j]==0) board[i][j]='X';
            }
        }


    }
};