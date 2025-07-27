// class Solution {
// public:
//     int n,m;
//      dfs(vector<int>&visited,int row,int col,vector<vector<int>>&answer,vector<vector<int>>&heights){
//             if(i>=n || j>=m) return 1;//atlantic =1 pasafic =2;
//             if(i<0 || j<0) return 2;
//         // }
//         visited[row][col]=1;
//         // if()
//         int left=0;
//         int right=0;
//         int down=0;
//         int top=0;

//         if(heights[row-1][col]<=heights[row][col]) top=dfs(visited,row-1,col,answer,heights);
//         if(heights[row][col-1]<=heights[row][col]) left=dfs(visited,row,col-1,answer,heights);
//         if(heights[row][col+1]<=heights[row][col]) right=dfs(visited,row,col+1,answer,heights);
//         if(heights[row+1][col]<=heights[row][col]) down=dfs(visited,row+1,col,answer,heights);

        
//         if(( left==1 || right==1 || top==1 || down ==1 ) && (left==2 || right==2 || top==2||down ==2))
//             answer.push_back({row,col});
//         }

//     }
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         n=heights.size();
//         m=heights[0].size();
//          vector<vector<int>>visited(n,vector<int>(m,0));
//          vector<int>ans;
//          for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(visited[i][j]==0) dfs(visited,i,j,ans,heights);
//             }
//          }
//          return ans;
//     }
// };
class Solution {
public:
    int n,m;
    void dfs(int val,int i,int j,vector<vector<int>>&visitedsea,vector<vector<int>>&heights){

        visitedsea[i][j]=1;
       int  dx[]={0,0,-1,1};
        int dy[]={1,-1,0,0};

        for(int k=0;k<4;k++){
            // if()
            int rowi=dx[k]+i;
            int coli=dy[k]+j;       
            if(rowi<n && rowi>-1 && coli>-1 && coli<m &&visitedsea[rowi][coli]==0 && heights[rowi][coli]>=val){
                dfs(heights[rowi][coli],rowi,coli,visitedsea,heights);
            }
        }
    }
     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        n=heights.size();
        m=heights[0].size();
        vector<vector<int>>visitedforpacific(n,vector<int>(m,0));
        vector<vector<int>>visitedforatlantic(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            dfs(heights[0][i],0,i,visitedforpacific,heights);
            dfs(heights[n-1][i],n-1,i,visitedforatlantic,heights);
        }
        for(int i=0;i<n;i++){
            dfs(heights[i][0],i,0,visitedforpacific,heights);
            dfs(heights[i][m-1],i,m-1,visitedforatlantic,heights);
        }
        // int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visitedforpacific[i][j]==1&&visitedforatlantic[i][j]==1) ans.push_back({i,j});
            }
        }
return ans;
     }
};
