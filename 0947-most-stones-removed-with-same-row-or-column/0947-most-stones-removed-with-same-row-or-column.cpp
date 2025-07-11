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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        dsu ds(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int ri=stones[i][0];
                int ci=stones[i][1];
                int rj=stones[j][0];
                int cj=stones[j][1];
                if(ri==rj || ci==cj){
                    ds.unionf(i,j);
                }
            }
        }
        int totalconnectedcomponets=0;
        for(int i=0;i<n;i++){
            if(ds.findultimateparent(i)==i) totalconnectedcomponets++;
        }
        return n-totalconnectedcomponets;
    }
};