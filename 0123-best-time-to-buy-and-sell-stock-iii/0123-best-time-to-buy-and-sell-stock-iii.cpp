class Solution {
public:
    int maxProfit(vector<int>&arr ) {
        int n=arr.size();
        vector<int> left(n,0),right(n,0);

        int mini=arr[0];
        for(int i=1;i<n;i++){
            mini=min(mini,arr[i]);
            left[i]=max(left[i-1],arr[i]-mini);
        }

        int maxi=arr[n-1];
        for(int i=n-2;i>=0;i--){
            maxi=max(maxi,arr[i]);
            right[i]=max(right[i+1],maxi-arr[i]);
        }
        
        int res=0;
        for(int i=0;i<n;i++){
            res=max(res,left[i]+right[i]);
        }
        return res;
    }
};