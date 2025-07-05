class Solution {
public:
    int n;
    void dfs(int i,vector<int>&visited,vector<vector<int>>&arr){
        // if(i>=n) return ;
        visited[i]=1;
        // for(int j=0;j<arr[i].size();j++){
            for(auto it:arr[i]){
            if(visited[it]==0){
                dfs(it,visited,arr);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& is) {
         n=is.size();
        vector<vector<int>> arr(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(is[i][j]==1){
                    arr[i].push_back(j);
                    arr[j].push_back(i);
                }
            }
        }
        int count=0;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(i,visited,arr);
                count++;
            }
        }
        return count;
    }
};