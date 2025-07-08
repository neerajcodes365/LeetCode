class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        // priority_queue<int,pair<int,int>>pq;
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        >pq;
        // miniihe
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int minidistance=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            int dx[]={0,0,-1,1,-1,-1,1,1};
            int dy[]={1,-1,0,0,-1,1,-1,1};

            for(int i=0;i<8;i++){
                int rowi=row +dx[i];
                int coli=col+dy[i];
                if(rowi<n && coli <n && rowi>-1 && coli>-1 && grid[rowi][coli]==0){
                    // dist[rowi][coli]=min(dist[row][col]+1,dist[rowi][coli]);
                    if(dist[rowi][coli]>dist[row][col]+1){
                        dist[rowi][coli]=dist[row][col]+1;
                        pq.push({dist[rowi][coli],{rowi,coli}});
                    }
                }
            }
        }
        return dist[n-1][n-1]==INT_MAX?-1:dist[n-1][n-1]+1;
    }
};