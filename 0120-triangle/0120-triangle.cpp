class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        //greedy approach 
    //     int size=a.size();
    //     int sum=a[0][0];
    //     // int sum;
    //     int index=0;
    //     for(int i=1;i<size;i++){
    //         if(a[i][index]<a[i][index+1]) {
    //             sum+=a[i][index];
    //         }
    //         else{
    //             index++;
    //             sum+=a[i][index];
    //         }
    //     }
    // return sum;
    // }
    vector<vector<int>>dp(a.size());
    for(int i=0;i<a.size();i++){
        dp[i]=vector<int>(a[i].size(),0);
    }
    dp[0][0]=a[0][0];
     for(int i = 1; i < a.size(); i++){
       for(int j = 0; j < a[i].size(); j++){
            int leftParent = (j > 0) ? dp[i-1][j-1] : INT_MAX;
             int rightParent = (j < dp[i-1].size()) ? dp[i-1][j] : INT_MAX;
            dp[i][j] = a[i][j] + min(leftParent, rightParent);
            }
        }
   
    int min=INT_MAX;
    for( int it=0;it<dp[a.size()-1].size();it++){
        if(dp[a.size()-1][it]<min)min=dp[a.size()-1][it];
    }
    return min;
    }
    
};