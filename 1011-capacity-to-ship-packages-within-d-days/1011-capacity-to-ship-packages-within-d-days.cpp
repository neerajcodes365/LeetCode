class Solution {
public:
    int help(vector<int>&weights,int value){
        int sum=0;
        int n=weights.size();
        int ans=1;
        for(int i=0;i<n;i++){
            if(sum+weights[i]>value){
                ans++;
                sum=weights[i];
            }else{
            sum+=weights[i];
            }
        }
        return ans;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int mini=INT_MIN;
        int sum=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            mini=max(mini,weights[i]);
            sum+=weights[i];
        }

        int low=mini;
        int high=sum;
        int ans=mini;
        while(low<=high){
            int mid=(low+high)/2;
            int daystocomplete=help(weights,mid);
            if(daystocomplete<=days){
                // ans=min(ans,mid);
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;

    }
};