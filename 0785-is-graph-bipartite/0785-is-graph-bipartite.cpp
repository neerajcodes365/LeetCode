class Solution {
public:
    void color(int i,vector<vector<int>>&graph,vector<int>&visited,int clr){
        // visited[i]=clr;
        queue<pair<int,int>>q;
        q.push({i,clr});
        while(!q.empty()){
            int index=q.front().first;
            int pcolor=q.front().second;
            q.pop();
            visited[index]=pcolor;
            for(auto it:graph[index]){
                    if(visited[it]==-1) q.push({it,(pcolor+1)%2});
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n,-1);
        // int j=0;
        for(int i=0;i<n;i++){
            if(visited[i]==-1) {
                color(i,graph,visited,0);
                // j++;
            }
        }

        bool ans=true;
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                if(visited[i]==visited[it]) ans=false;
            }
        }

        return ans;
    }
};