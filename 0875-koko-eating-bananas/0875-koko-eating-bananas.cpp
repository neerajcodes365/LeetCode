class Solution {
public:
    long long help(vector<int>&piles,int k){
        long long ans=0;
        int n=piles.size();

        for(int i=0;i<n;i++){
            int num=piles[i]/k;
            int rem=piles[i]%k;
            if(rem==0){
                ans+=num;
            }else{
                // ans++;
                ans+=num+1;
            }
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxi=INT_MIN;//max of list
        int mini=1;//

        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }

        int low=mini;
        int high=maxi;
        int ans=maxi;

        while(low<=high){
            int mid=low+(high-low)/2;
            // int mid=(low+high)/2;

            long long a=help(piles,mid);
            if(a<=h){
                high=mid-1;
                // ans=min(ans,mid);
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        return ans;

    }
};