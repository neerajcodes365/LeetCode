class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        // vector<int>nxtmax(n,0);
        int maxi=p[n-1];
        int ans=0;
        for(int i=n-2;i>=0;i--){
            if(p[i]<maxi) ans=max(ans,maxi-p[i]);
            else{
                maxi=p[i];
            }
        }
        return ans;
    }
};