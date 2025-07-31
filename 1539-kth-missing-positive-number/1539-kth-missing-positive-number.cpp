class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=0;
        int n=arr.size();
        int j=n-1;

        while(i<=j){
            int mid=i+(j-i)/2;
            int kval=arr[mid]-mid+1;
            if(kval<=k){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }

        // return arr[j]+k-(arr[j]-(j+1));
        // return k+j-1;
        return k+j+1;

    }
};