// class Solution {
// public:
// int n;             TLEEEEEEEEEEE,calling bfs somany times ,to reduce it ,starting a mutlipoint bfs from all 0s . distance can be given from adding 1 to the q row and col 
// int m;

// int bfs(int i,int j,vector<vector<int>>& mat){
//     vector<vector<int>> vis(n,vector<int>(m,0));
//     queue<pair<pair<int,int>,int>> q;
//     q.push({{i,j},0});
//     vis[i][j]=1;

//     while(!q.empty()){
//         int row=q.front().first.first;
//         int col=q.front().first.second;
//         int dist=q.front().second;
//         q.pop();

//         if(mat[row][col]==0)return dist;

//         if(row+1<n && !vis[row+1][col]){
//             q.push({{row+1,col},dist+1});
//             vis[row+1][col]=1;
//         }
//         if(col+1<m && !vis[row][col+1]){
//             q.push({{row,col+1},dist+1});
//             vis[row][col+1]=1;
//         }
//         if(row-1>=0 && !vis[row-1][col]){
//             q.push({{row-1,col},dist+1});
//             vis[row-1][col]=1;
//         }
//         if(col-1>=0 && !vis[row][col-1]){
//             q.push({{row,col-1},dist+1});
//             vis[row][col-1]=1;
//         }
//     }
//     return 0;
// }

// vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
//     n=mat.size();
//     m=mat[0].size();
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(mat[i][j]==1){
//                 mat[i][j]=bfs(i,j,mat);
//             }
//         }
//     }
//     return mat;
// }
// };
class Solution {
public:
int n;
int m;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
    n=mat.size();
    m=mat[0].size();
    queue<pair<pair<int,int>,int>> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                q.push({{i,j},0});
            }else{
                mat[i][j]=-1;
            }
        }
    }

    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int level=q.front().second;
        q.pop();

        for(int k=0;k<4;k++){
            int nrow=row+dx[k];
            int ncol=col+dy[k];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]==-1){
                mat[nrow][ncol]=level+1;
                q.push({{nrow,ncol},level+1});
            }
        }
    }

    return mat;
}
};
