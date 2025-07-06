class Solution {
public:
    bool dfscycle(int i,vector<vector<int>>&graph,vector<int>&pathvisited,vector<int>&visited){

        visited[i]=1;
        pathvisited[i]=1;
        for(auto it:graph[i]){
            if(visited[it]==-1 && dfscycle(it,graph,pathvisited,visited))return true;
            else if(pathvisited[it]==1) return true;
        }

pathvisited[i]=-1;
return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n,-1);
        vector<int>pathvisited(n,-1);
        for(int i=0;i<n;i++){
            if(visited[i]==-1) 
            bool oke=dfscycle(i,graph,pathvisited,visited);
        }
    vector<int>ans;
    // for(auto it: pathvisited)
    for(int i=0;i<n;i++){
        if(pathvisited[i]!=1)ans.push_back(i);
    }
    
    return ans;
    }
};