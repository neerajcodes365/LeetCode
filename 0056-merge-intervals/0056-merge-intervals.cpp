class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end());
        vector<vector<int>>ans;
        int n=inter.size();
        int i=0;
        if(n==1)return inter;
        while(i<n){ 
            int first=inter[i][0];
            int second=inter[i][1];

            // int nextf=inter[i+1][0];
            // int nexts=inter[i+1][1];
            int n1=first;
            int n2=second;
            while(i<n-1 && n2>=inter[i+1][0]){
               n1 =min(n1,inter[i+1][0]);
               n2=max(n2,inter[i+1][1]);
               i++;
            }
            ans.push_back({n1,n2});
            i++;
        }
        return ans;

    }
};