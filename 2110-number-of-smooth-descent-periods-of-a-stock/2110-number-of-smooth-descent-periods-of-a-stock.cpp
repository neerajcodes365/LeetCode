class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        long long int ans=1;
        long long int cnt=1;
        for( int i=1;i<n;i++){
            if(prices[i-1]-prices[i]==1)cnt++;
            else cnt=1;                
            ans+=cnt;
        }
        return ans;
    }
};