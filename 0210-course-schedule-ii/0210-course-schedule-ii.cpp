// class Solution {
// public:
//     vector<int> findOrder(int num, vector<vector<int>>& pre) {
//         int n=num;
//         int size=pre.size();
//         vector<vector<int>>adj(n);
        
//         for(int i=0;i<size;i++){
//             // for(auto it)
//             int num=pre[i][0];
//             int ad=pre[i][1];
//             adj[num].push_back(ad);
//         }
//          queue<int>q;
//          vector<int> topo;
//         // int count=0;
//          vector<int> incoming(num,0);
//          for(int i=0;i<num;i++){
//             for(auto it:adj[i]){
//                 incoming[it]++;
//             }
//          }

//         for(int i=0;i<num;i++)
//         {
//             if(incoming[i]==0) q.push(i);
//         }
//         while(!q.empty()){
//             int number=q.front();
//             q.pop();
//             topo.push_back(number);
//             // count++;
//             for(auto it:adj[number]){
//                 incoming[it]--;
//                 if(incoming[it]==0) q.push(it);
//             }
//         }

//         reverse(topo.begin(),topo.end());
//         vector<int>nothing;
// return topo.size()==num?topo:nothing;

//     }
// };


class Solution {
public:
    void dfs(int i,vector<vector<int>>&adj,stack<int>&st,vector<int>&visited){
        visited[i]=1;
        for(auto ad:adj[i]){
            if(visited[ad]==0) dfs(ad,adj,st,visited);
        }
        st.push(i);
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        stack<int>st;
        vector<int>visited(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<pre.size();i++){
            // adj[pre[i][0]].push_back(pre[i][1]);
            adj[pre[i][1]].push_back(pre[i][0]);


        }
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(i,adj,st,visited);
            }
        }
vector<int>ans;
while(!st.empty()){
    ans.push_back(st.top());
    st.pop();
}
vector<int>empty;
return n==ans.size()?ans:empty;
    }
};