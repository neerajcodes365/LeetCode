class dsu{
    public:
    vector<int>parent,size;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        dsu ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int dx[]={0,0,1,-1};
                    int dy[]={1,-1,0,0};
                    for(int k=0;k<4;k++){
                        int rowi=i+dx[k];
                        int coli=j+dy[k];
                        if( rowi<n && coli<n && rowi>-1 && coli>-1 && grid[rowi][coli]==1){
                            int current=i*n+j;
                            int adj=n*rowi+coli;
                            ds.unionf(current,adj);
                        }
                    }
                }
            }
        }


int total=0;

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(grid[i][j]==1){
        //             int parent = ds.findultimateparent(i*n+j);
        //             total = max(total, ds.size[parent]);
        //         }
        //     }
        // }





    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                int parent = ds.findultimateparent(i*n+j);
                total = max(total, ds.size[parent]);   
            }
            else if(grid[i][j]==0){
                    int dx[]={0,0,1,-1};
                    int dy[]={1,-1,0,0};
                    unordered_set<int>index;
                    for(int k=0;k<4;k++){
                        int rowi=i+dx[k];
                        int coli=j+dy[k];
                        if( rowi<n && coli<n && rowi>-1 && coli>-1 && grid[rowi][coli]==1){
                            // index.insert(n*rowi+coli);
                            int father=ds.findultimateparent(n*rowi+coli);
                            index.insert(father);
//same part nte sanam anakil skip ,appo same part nte ano check cheyan parent vechu thane nokanam
                        }
                    }
                    int count=1;
                    // for(auto parent:index){
                    //     int ultimateparent=ds.findultimateparent(parent);
                    //     count+=ds.size[ultimateparent];
                    // }
                    for(auto parent:index){
                        // int ultimateparent=ds.findultimateparent(parent);
                        count+=ds.size[parent];
                    }
                    total=max(total,count);
        }
    }
}
    return total;

    }
};