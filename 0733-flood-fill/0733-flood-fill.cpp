class Solution {
public:
int n;
int m;
void dfs(int row,int col,vector<vector<int>>&grid,int color,int num){
    if(row<0 || col<0 || row>=n || col>=m || grid[row][col]!=num) return;
    grid[row][col]=color;
    if(col+1<m && grid[row][col+1]==num) dfs(row,col+1,grid,color,num);
    if(row+1<n && grid[row+1][col]==num) dfs(row+1,col,grid,color,num);
    if(col-1>=0 && grid[row][col-1]==num) dfs(row,col-1,grid,color,num);
    if(row-1>=0 && grid[row-1][col]==num) dfs(row-1,col,grid,color,num);
}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n=image.size();
        m=image[0].size();
        int num=image[sr][sc];
        if(num!=color)dfs(sr,sc,image,color,num);
        return image;
    }
};