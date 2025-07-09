class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>distance(n+1,INT_MAX);
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            int node=times[i][0];
            int end=times[i][1];
            int wet=times[i][2];
            adj[node].push_back({end,wet});
        }
        distance[k]=0;
        priority_queue<
        pair<int,int>,//dist,node
        vector<pair<int,int>>,
        greater<pair<int,int>>
        >pq;
        pq.push({0,k});

        while(!pq.empty()){
            int nod=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
            
            for(int i=0;i<adj[nod].size();i++){
                int endnode=adj[nod][i].first;
                int edge=adj[nod][i].second;
                int total=edge+dist;
                if(distance[endnode]>total){
                    distance[endnode]=total;
                    pq.push({total,endnode});
                }
            }
        }
        int mini=INT_MIN;
        // int flag=0;
        for(int i=1;i<=n;i++){
            // if(dis)
            mini=max(mini,distance[i]);
            if(distance[i]==INT_MAX) return -1;
        }
        return mini;
    
    }
};