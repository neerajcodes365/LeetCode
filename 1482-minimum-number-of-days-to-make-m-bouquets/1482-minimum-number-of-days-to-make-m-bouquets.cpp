class Solution {
public:
int n;
    bool help(vector<int>& bloom, int m, int k,int day){
        int count=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(bloom[i]<=day){
                count++;
                if(count==k){
                    ans++;
                    count=0;
                }
            }else{
                count=0;
            }
        }
        return ans>=m;
    }
    int minDays(vector<int>& bloom, int m, int k) {
        n=bloom.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            mini=min(mini,bloom[i]);
            maxi=max(maxi,bloom[i]);
        }
        int ans=-1;
        int low=mini;
        int high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            bool booli=help(bloom,m,k,mid);
            if(booli){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};