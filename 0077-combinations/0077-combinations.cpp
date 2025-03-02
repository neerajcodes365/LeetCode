class Solution {
public:

    void solve(vector<vector<int>>&result,vector<int>&arr,int size,int n,int index){
        if(arr.size()==size){
           // sort(arr.begin(),arr.end());
            //auto it=find(result.begin(),result.end(),arr);
            //if(it==result.end()){
            result.push_back(arr);  
            //}
            
            return;
        }
        for(int i=index;i<=n;i++){
            arr.push_back(i);
            solve(result,arr,size,n,i+1);
            arr.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>result;
        vector<int>arr;
        int index=1;
        solve(result,arr,k,n,index);
        return result;
    }
};