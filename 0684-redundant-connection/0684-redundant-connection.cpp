class dsu{
    

 public:
    vector<int>parent,size;
    int n;
    dsu(int a){
        this->n=a;
    parent.resize(n,-1);
    size.resize(n,1);
      for(int i=0;i<n;i++){
        parent[i]=i;
    }
    }
    
  

    int findultimateparent(int a){
        if(parent[a]==a) return a;
        return parent[a]=findultimateparent(parent[a]);
    }

    void fsunion(int a,int b ){
        // if()
        int upa=findultimateparent(a);
        int upb=findultimateparent(b);
        if(upa==upb)return;

        if(size[upa]>=size[upb]){
            parent[upb]=upa;
            size[upa]+=size[upb];
        }
        else{
            parent[upa]=upb;
            size[upb]+=size[upa];
        }
    }
   
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        dsu ds(n+1);
        vector<int>st;
        for(int i=0;i<n;i++){
            int a=edges[i][0];
            int b=edges[i][1];
            if(ds.findultimateparent(a)==ds.findultimateparent(b)) st={a,b};
            else ds.fsunion(a,b);
        }
        return st;
    }
};