class Solution {
public:

int ans;

void dfs(int i,vector<int>& pathvisited,vector<int>&visited,vector<int>& edges,unordered_map<int,int>&mp,int length){
        visited[i]=1;
        pathvisited[i]=1;
        mp[i]=length;
        int adjnode=edges[i];
        if(adjnode!=-1){
            if(visited[adjnode]!=1){
                dfs(adjnode,pathvisited,visited,edges,mp,length+1);
            }else if(pathvisited[adjnode]==1){
                ans=max(ans,length-mp[adjnode]+1);
            }
        }

        pathvisited[i]=0;
        return;
}


    int longestCycle(vector<int>& edges) {
        ans=-1;
       int n=edges.size();
       vector<int>visited(n,0);
       vector<int>pathvisited(n,0);

       for(int i=0;i<n;i++){
        unordered_map<int,int>mp;
        if(visited[i]==0) dfs(i,pathvisited,visited,edges,mp,0);
       }

       return ans;
    }
};