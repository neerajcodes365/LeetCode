class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
         vector<vector<int>>adj(n,vector<int>(n,INT_MAX));
         for(int i=0;i<n;i++)adj[i][i]=0;
         for(int i=0;i<edges.size();i++){
            // auto [from,to,weight]=edges[i];
            int from = edges[i][0];
            int to = edges[i][1];
            int weight = edges[i][2];
            adj[from][to]=weight;
            adj[to][from]=weight;
         }
         for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adj[i][k]!=INT_MAX&&adj[k][j]!=INT_MAX)
                        adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
        int large=INT_MAX;
        int nm=-1;
        for(int i=0;i<n;i++){
           int count=0;
            for(int j=0;j<n;j++){
                if(i!=j && adj[i][j]<=threshold) count++;
            }
            if(count<=large){
                nm=i;
                large=count;
            }
        }
        return nm;
    }
};