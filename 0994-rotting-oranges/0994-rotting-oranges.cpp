// class Solution {
// public:
//     int count;
//     int n;
//     void bfs(int i,int j,vector<vector<int>>& grid){
//         queue<pair<int,int>>q;
//         q.push({i,j});
//         grid[i][j]=0;
//         while(!q.empty()){
//             // int row;
//             // int col;
//             int size=q.size();
//             for(int i=0;i<size;i++){

//             pair<int,int>p=q.front();
//             int row=p.first;
//             int col=p.second;
//             q.pop();
//             grid[row][col]=0;

//             if(i-1>0 && j-1 >0 && i+1<n && j+1<n && grid[i][j+1]==1) q.push({i,j+1});//
//             if(i-1>0 && j-1 >0 && i+1<n && j+1<n && grid[i+1][j]==1) q.push({i+1,j});//dowm
//             if(i-1>0 && j-1 >0 && i+1<n && j+1<n && grid[i-1][j]==1) q.push({i-1,j});//top
//             if(i-1>0 && j-1 >0 && i+1<n && j+1<n && grid[i-1][j-1]==1) q.push({i-1,j-1});//left

//             }
//             count++;
//         }
//     }
//     int orangesRotting(vector<vector<int>>& grid) {
//         count=0;
//          n=grid.size();
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]==2){
//                     bfs(i,j,grid);
//                 }
//             }
//         }

//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]==1)return -1;
//                 // if(grid[i][j])
//             }
//         }
    
// return count;


//     }
// };
class Solution {
public:
    int count;
    int n,m;

    void bfs(int i,int j,vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        q.push({i,j});

        while(!q.empty()) {
            int sz=q.size();
            bool flag=false;

            for(int k=0;k<sz;k++) {
                pair<int,int> p=q.front();
                q.pop();
                int row=p.first;
                int col=p.second;

                if(col+1<m && grid[row][col+1]==1) {
                    grid[row][col+1]=2;
                    q.push({row,col+1});
                    flag=true;
                }
                if(row+1<n && grid[row+1][col]==1) {
                    grid[row+1][col]=2;
                    q.push({row+1,col});
                    flag=true;
                }
                if(col-1>=0 && grid[row][col-1]==1) {
                    grid[row][col-1]=2;
                    q.push({row,col-1});
                    flag=true;
                }
                if(row-1>=0 && grid[row-1][col]==1) {
                    grid[row-1][col]=2;
                    q.push({row-1,col});
                    flag=true;
                }
            }

            if(flag) count++;
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        count=0;
        n=grid.size();
        m=grid[0].size();

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==2) {
                    bfs(i,j,grid);
                }
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1) return -1;
            }
        }

        return count;
    }
};
