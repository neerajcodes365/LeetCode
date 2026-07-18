// class Solution {
// public:
//     long long dfs(vector<vector<int>>&adj,int node,vector<int>&basetime){
//         if(adj[node].empty())return basetime[node];
//         long long l=LONG_MIN;
//         long long ee=LONG_MAX;
//         for(auto e:adj[node]){
//             long long x=dfs(adj,e,basetime);
//             l=max(l,x);
//             ee=min(ee,x);
//             return l + (l - ee + basetime[node]);
//         }
//         return 0;
//     }

//     long long finishTime(int n, vector<vector<int>>& edges, vector<int>& basetime) {
//         vector<vector<int>>adj(n);
//         for(auto e:edges){
//             int u=e[0];
//             int v=e[1];
//             adj[u].push_back(v);
//         }
//         return dfs(adj,0,basetime);
//     }
      
// };
class Solution {
public:
    long long dfs(vector<vector<int>>& adj, int node, vector<int>& basetime) {

        if (adj[node].empty())
            return basetime[node];

        long long mx = LLONG_MIN;
        long long mn = LLONG_MAX;

        for (int child : adj[node]) {
            long long t = dfs(adj, child, basetime);
            mx = max(mx, t);
            mn = min(mn, t);
        }

        return mx + (mx - mn + basetime[node]);
    }

    long long finishTime(int n, vector<vector<int>>& edges,
                         vector<int>& basetime) {

        vector<vector<int>> adj(n);

        for (auto &e : edges)
            adj[e[0]].push_back(e[1]);

        return dfs(adj, 0, basetime);
    }
};