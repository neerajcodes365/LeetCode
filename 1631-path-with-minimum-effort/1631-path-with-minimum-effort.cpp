class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>distance(n,vector<int>(m,INT_MAX));
        distance[0][0]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        while(!q.empty()){
            int dist=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            int dx[]={0,0,-1,1};
            int dy[]={1,-1,0,0};
            q.pop();
            for(int i=0;i<4;i++){
                int rowi=row+dx[i];
                int coli=col+dy[i];
                
                // if(rowi<n && coli<m && coli>-1 && rowi>-1 ){
                //     if(distance[rowi][coli]>abs(heights[rowi][coli]-dist)){
                //         distance[rowi][coli]=abs(heights[rowi][coli]-dist);
                //         q.push({abs(heights[rowi][coli]-dist),{rowi,coli}});
                //     }
                // }
                
                if(rowi<n && coli<m && coli>-1 && rowi>-1 ){
                    if(distance[rowi][coli]>abs(heights[rowi][coli]-heights[row][col])){
                        distance[rowi][coli]=abs(heights[rowi][coli]-heights[row][col]);
                        q.push({abs(heights[rowi][coli]-heights[row][col]),{rowi,coli}});
                    }
                }


            }

        }
        return distance[n-1][m-1];
    }
};