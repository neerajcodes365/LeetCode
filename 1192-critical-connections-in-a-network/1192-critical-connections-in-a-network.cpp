class Solution {
public:
int timer;
    void dfs(int node,int parent,vector<int>&visited,vector<int>&dfstime,vector<int>&lowtime,vector<vector<int>>&adj,vector<vector<int>>&ans){
        visited[node]=1;
        lowtime[node]=dfstime[node]=timer;
        timer++;
        for(auto v:adj[node]){
            if(v==parent)continue;
            if(visited[v]==0){
                dfs(v,node,visited,dfstime,lowtime,adj,ans);
                lowtime[node]=min(lowtime[node],lowtime[v]);
                if(dfstime[node]<lowtime[v]){
                    ans.push_back({node,v});
                }
            }else{
                lowtime[node]=min(lowtime[node],lowtime[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
         vector<vector<int>>adj(n);

         for(int i=0;i<con.size();i++){
            adj[con[i][0]].push_back(con[i][1]);
            adj[con[i][1]].push_back(con[i][0]);
         }
        vector<int>visited(n,0);
        vector<int>dfstime(n,0);
        vector<int>lowtime(n,0);
         vector<vector<int>>ans;
         timer=0;
         dfs(0,-1,visited,dfstime,lowtime,adj,ans);
         return ans;
    }
};