class Solution {
private:
       bool binarysearch(vector<vector<int>>& mt,int tar,int start,int end,int csize){
       if(start>end) return false;
       int mid=start-(start-end)/2;
       int row=mid/csize;
       int col=mid%csize;
       if(mt[row][col]==tar) return true;
       if(mt[row][col] <tar) return binarysearch(mt,tar,mid+1,end,csize);
       else return binarysearch(mt,tar,start,end-1,csize);
       }
public:
    bool searchMatrix(vector<vector<int>>& mt, int tar) {
        int m=mt.size();
        int n=mt[0].size();
        return binarysearch(mt,tar,0,m*n-1,n);
    }
};