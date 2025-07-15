class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>distance(n,vector<int>(n,INT_MAX));
        priority_queue<
        pair<int,pair<int,int>>,// node val,i,j
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        >pq;
        distance[0][0]=grid[0][0];

        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()){
            int nodeval=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            // if(nodeval>distance[row][col]) continue;
            if(row==n-1 && col==n-1)return nodeval;
            int dx[]={0,0,1,-1};
            int dy[]={1,-1,0,0};
            for(int i=0;i<4;i++){
                int rowi=row+dx[i];
                int coli=col+dy[i];
                if(rowi<n && coli<n && rowi>-1 && coli>-1){
                    int maxval=max(nodeval,grid[rowi][coli]);
                    if(maxval<distance[rowi][coli]){
                        distance[rowi][coli]=maxval;
                        pq.push({maxval,{rowi,coli}});
                    }
                }
            }
        }
        return distance[n-1][n-1];
    }
};