class Solution {
public:
int mini;
int n,m;

    void bfs(int r,int c,int disti,vector<vector<char>>& maze,vector<vector<int>>& visited){
        queue<tuple<int,int,int>>q;//row,col,dist
        int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
        q.push({r,c,disti});
        while(!q.empty()){
            // auto[]
            auto[i,j,dist]=q.front();
            q.pop();
        
        if(visited[i][j]==1) continue;
        visited[i][j]=1;
        
       if((i == 0 || j == 0 || i == n - 1 || j == m - 1) && !(i == r && j == c)) mini=min(mini,dist);

        for(int k=0;k<4;k++){
            int rowi=i+dx[k];
            int coli=j+dy[k];
            if(rowi<n && coli<m && rowi>-1 && coli>-1 && maze[rowi][coli]!='+' && visited[rowi][coli]==0){
                q.push({rowi,coli,dist+1});
            }
        }
    }
}
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        n=maze.size();
        m=maze[0].size();
        int i=entrance[0];
        int j=entrance[1];
        vector<vector<int>>visited(n,vector<int>(m,0));
        mini=INT_MAX;
        bfs(i,j,0,maze,visited);
        return mini==INT_MAX?-1:mini;
    }
};