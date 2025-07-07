class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        int n=num;
        int size=pre.size();
        vector<vector<int>>adj(n);
        
        for(int i=0;i<size;i++){
            // for(auto it)
            int num=pre[i][0];
            int ad=pre[i][1];
            adj[num].push_back(ad);
        }
         queue<int>q;
         vector<int> topo;
        // int count=0;
         vector<int> incoming(num,0);
         for(int i=0;i<num;i++){
            for(auto it:adj[i]){
                incoming[it]++;
            }
         }

        for(int i=0;i<num;i++)
        {
            if(incoming[i]==0) q.push(i);
        }
        while(!q.empty()){
            int number=q.front();
            q.pop();
            topo.push_back(number);
            // count++;
            for(auto it:adj[number]){
                incoming[it]--;
                if(incoming[it]==0) q.push(it);
            }
        }

        reverse(topo.begin(),topo.end());
        vector<int>nothing;
return topo.size()==num?topo:nothing;

    }
};