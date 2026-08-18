class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int flag=0;
        int ans=0;
        int n=arr.size();
        int mini=arr[0];
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                // flag++;
                // if(flag!=1){
                    ans+=arr[i]-mini;
                // }
                    mini=arr[i+1];
            }
            // else{
            //     mini=arr[]
            // }
        }
        ans+=(arr[n-1]-mini);
        return ans;
    }
};