class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        int const mod=1e9+7;
        // vector<int>distance(n,INT_MAX);
        vector<long long> distance(n, LLONG_MAX);
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<roads.size();i++){
            int node=roads[i][0];
            int end=roads[i][1];
            int wet=roads[i][2];
            adj[node].push_back({end,wet});
            adj[end].push_back({node,wet});

        }
        distance[0]=0;
        priority_queue<
        pair<int,int>,//dist,node
        vector<pair<int,int>>,
        greater<pair<int,int>>
        >pq;
        pq.push({0,0});

        // int count=1; 
        vector<int>count(n,0);
        count[0]=1;


        while(!pq.empty()){
            int nod=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
            if(dist>distance[nod]) continue;
            for(int i=0;i<adj[nod].size();i++){
                int endnode=adj[nod][i].first;
                int edge=adj[nod][i].second;
                // int total=edge+dist;
                long long int total=edge+dist;

                // if(endnode==n-1){
                //     if(distance[n-1]==total) count++;
                // }
                if(distance[endnode]>total){
                    // if(endnode==n-1) count=1;
                    distance[endnode]=total;
                    pq.push({total,endnode});
                    count[endnode]=count[nod];
                }else if(distance[endnode]==total){
                    count[endnode] = (count[endnode] + count[nod]) % mod;
                }
            }
        }
        return count[n-1];
    }
};