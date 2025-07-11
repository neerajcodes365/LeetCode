class dsu{
    vector<int>parent,size;
    public:
        dsu(int n){
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
    
    int findultimateparent(int i){
            if(parent[i]==i) return i;
            return parent[i]=findultimateparent(parent[i]);
    }

    void unionf(int a,int b){
        int utpa=findultimateparent(a);
        int utpb=findultimateparent(b);
        if(utpa==utpb) return;
        if(size[utpa]>size[utpb]){
            parent[utpb]=utpa;
            size[utpa]+=size[utpb];
        }else if(size[utpb]>size[utpa]){
            parent[utpa]=utpb;
            size[utpb]+=size[utpa];
        }else{
            parent[utpb]=utpa;
            size[utpa]+=size[utpb];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& con) {
        /* 
        
        1st mst cheya ,ethrea edges remaining ind noka ,
        e edges ind nu vecho, appo reamaing edges um nte count aduka be rem
        then n-e+1 < rem -1 anakil set avum;
        
        */

        // vector<vector<int>>adj(n);
        // for(int i=0;i<con.size();i++){
        //     int u=con[i][0];
        //     int v=con[i][1];
        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }

            dsu ds(n);
            int includedge=0;
            int excludedge=0;
            for(int i=0;i<con.size();i++){
                int u=con[i][0];
                int v=con[i][1];
                if(ds.findultimateparent(u)!=ds.findultimateparent(v)){
                    includedge++;
                    ds.unionf(u,v);
                }else excludedge++;
            }
            // if(n-includedge+1<excludedge-1){
            //     return n-includedge+1;
            // }
            int excludedcomputer=0;
            for(int i=0;i<n;i++)
                if(ds.findultimateparent(i)==i) excludedcomputer++;

            // if(excludedge>=excludedcomputer-1) return excludedcomputer-1;
             if(excludedge >= excludedcomputer - 1) return excludedcomputer - 1;
        
            return -1;
    }
};