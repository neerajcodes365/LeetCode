class Solution {
public:
#define ll long long
// using ll=long long ;
    long long splitArray(vector<int>& arr) {
        int n=arr.size();
        int l=0,r=n-1;
        long long lsum=0,rsum=0;

        while(l<n-1 && arr[l]<arr[l+1]){
            lsum+=arr[l++];
        }
        while(r>0 && arr[r]<arr[r-1]){
            rsum+=arr[r--];
        }

        if(l==r){
            ll a=abs((lsum+arr[l])-rsum);
            ll b=abs(lsum-(rsum+arr[r]));
            return min(a,b);
        }

        else if( r-l==1){
            return abs(lsum -rsum);
        }
return -1;
    }
};