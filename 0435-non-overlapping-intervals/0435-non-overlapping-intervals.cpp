class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        int n=inter.size();
        sort(inter.begin(),inter.end());
        int i=0;
        int ans=0;

        while(i<n){
            int n1=inter[i][0];
            int n2=inter[i][1];
            while(i<n-1 && n2>inter[i+1][0]){
                ans++;
                i++;
            }
            i++;
        }
return ans;
    }
};


/* 
class Solution {
public:
    static bool customComparator(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1]; // Descending for second element if start equal
        return a[0] < b[0];     // Ascending for first element
    }
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end(),customComparator);
        vector<vector<int>>ans;
        int n=inter.size();
        int i=0;
        if(n==1)return 0;
        while(i<n){ 
            int first=inter[i][0];
            int second=inter[i][1];

            // int nextf=inter[i+1][0];
            // int nexts=inter[i+1][1];
            int n1=first;
            int n2=second;
            while(i<n-1 && n2>inter[i+1][0]){
               n1 =min(n1,inter[i+1][0]);
               n2=max(n2,inter[i+1][1]);
               i++;
            }
            ans.push_back({n1,n2});
            i++;
        }
        return n-ans.size();
    }
};

*/