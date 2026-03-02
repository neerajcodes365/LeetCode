class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>dis(n,0);
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==0)cnt++;
                else break;
            }
            dis[i]=cnt;
        }
int ans=0;
        for(int i=0;i<n;i++){
            int need=n-i-1;
            int j=i;
            while(j<n&&dis[j]<need){
                j++;
            }
            if(j==n) return -1;
            ans+=j-i;
            while(j>i){
                swap(dis[j],dis[j-1]);
                j--;
            }
        }
        return ans;
    }
};