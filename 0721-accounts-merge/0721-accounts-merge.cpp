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
/* working brute force 
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acnt) {
        int n = acnt.size();
        dsu ds(n);
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(acnt[i][0] == acnt[j][0]){
                    for(int iti = 1; iti < acnt[i].size(); iti++){
                        for(int itj = 1; itj < acnt[j].size(); itj++){
                            if(acnt[i][iti] == acnt[j][itj]){
                                ds.unionf(i, j);
                                break; 
                            }
                        }
                    }
                }
            }
        }
        
        unordered_map<int, set<string>> groups;
        for(int i = 0; i < n; i++){
            int parent = ds.findultimateparent(i);
            for(int j = 1; j < acnt[i].size(); j++){
                groups[parent].insert(acnt[i][j]);
            }
        }
        
        vector<vector<string>> result;
        for(auto& group : groups){
            vector<string> account;
            int parentIdx = group.first;
            account.push_back(acnt[parentIdx][0]); 
            
            for(const string& email : group.second){
                account.push_back(email);
            }
            
            result.push_back(account);
        }
        
        return result;
    }
};
*/
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acnt) {
        int n = acnt.size();
        dsu ds(n);
        
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<acnt[i].size();j++){
                if(mp.count(acnt[i][j])){
                    ds.unionf(i,mp[acnt[i][j]]);
                }else{
                    mp[acnt[i][j]]=i;
                }
            }
        }
        unordered_map<int,set<string>>mpp;
        for( auto [mail,index] :mp){
            int ulpat=ds.findultimateparent(index);
            mpp[ulpat].insert(mail);
        }



        
        vector<vector<string>> result;
        for( auto [index,setofmail]:mpp){
            vector<string>ans;
            ans.push_back(acnt[index][0]);
            for(auto mail:setofmail){
                ans.push_back(mail);
            }
            result.push_back(ans);
        }

        
        
        return result;
    }
};

