class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n); 
        for (auto& e : edges) {
            int node = e[0], neigh = e[1], wt = e[2];
            adj[node].push_back({neigh, wt});
        }
        const int INF = INT_MAX;
        vector<vector<int>> dist(n, vector<int>(k + 1, INF));//this was the thing i missed .
        // pq: {distance, node, count}
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, node, cnt] = pq.top();
            pq.pop();

            if (d > dist[node][cnt]) continue; 
            if (node == n - 1) return d;        
            for (auto& [neigh, wt] : adj[node]) {
                int newCnt;
                if (labels[neigh] == labels[node]) newCnt = cnt + 1;
                else newCnt = 1;

                if (newCnt > k) continue; 
                int nd = d + wt;
                if (nd < dist[neigh][newCnt]) {
                    dist[neigh][newCnt] = nd;
                    pq.push({nd, neigh, newCnt});
                }
            }
        }

        int ans = INF;
        for (int c = 1; c <= k; c++) ans = min(ans, dist[n-1][c]);
        return ans == INF ? -1 : ans;
    }
};