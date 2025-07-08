// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         vector<int>distance(n,INT_MAX);
//         distance[src]=0;
//         vector<vector<pair<int,int>>>adj(n);
//         for(int i=0;i<flights.size();i++){
//             int node=flights[i][0];
//             int to=flights[i][1];
//             int price=flights[i][2];
//             adj[node].push_back({to,price});
//         }
//         priority_queue<
//         pair<int,pair<int,int>>,//k,<node,min price
//         vector<pair<int,pair<int,int>>>,
//         greater<pair<int,pair<int,int>>>
//         >pq;
//         pq.push({0,{src,0}});
//         while(!pq.empty()){
            
//         int ku=pq.top().first;
//         int nod=pq.top().second.first;
//         int pri=pq.top().second.second;

//         if(nod==dst) return distance[dst];
//         pq.pop();
// if( ku <=k){
//         for(int it=0;it<adj[nod].size();it++){
//             if(distance[adj[nod][it].first]>pri ){
//                 distance[adj[nod][it].first]=pri;
//                 pq.push({ku+1,{adj[nod][it].first,adj[nod][it].second}});
//             }
//         }
//     }

// }

//     // return distance[dst]==INT_MAX?-1:distance[dst];
//     return -1;


        
//     }
// };

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>distance(n,INT_MAX);
        distance[src]=0;
        vector<vector<pair<int,int>>>adj(n);
        
        for(int i=0;i<flights.size();i++){
            int node=flights[i][0];
            int to=flights[i][1];
            int price=flights[i][2];
            adj[node].push_back({to,price});
        }
       
        queue<tuple<int,int,int>>q;//k,node,money
        q.push({0,src,0});
       
        while(!q.empty()){
            auto [kval, node, money] = q.front();
            // int kval=get<0>q.front();
            // int node=get<1>q.front();
            // int money=get<2>q.front();
            q.pop();
            if(kval > k) continue;
            // if(kval<k+2){
                for(int i=0;i<adj[node].size();i++ ){
                    int negi=adj[node][i].first;
                    int edegmoney=adj[node][i].second;
                        int total=money+edegmoney;
                    if(distance[negi]>total){
                        distance[negi]=total;
                        q.push({kval+1,negi,total});
                    }
                }   
            // }
        }
        return distance[dst]==INT_MAX?-1:distance[dst];
        }
};