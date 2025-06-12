class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n=arr.size();
        int left,right;
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int top=arr[i-1][j];
                if(j-1<0){
                    left=INT_MAX;
                }else{
                    left=arr[i-1][j-1];
                }
                if(j+1>n-1){
                    right=INT_MAX;
                }else{
                    right=arr[i-1][j+1];
                }
                int mini=min(left,right);
                arr[i][j]+=min(top,mini);
            }
        }
        int min=INT_MAX;
        for(int i=0;i<n;i++){
            if(arr[n-1][i]<min)min=arr[n-1][i];
        }
        return min;
    }
};