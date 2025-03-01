class Solution {
public:
    void solve(vector<vector<int>>&result,vector<int>&arr,vector<int>&nums,int size){
        if(size==0){
            result.push_back(arr);
            return;
        }
        for(auto it:nums){
            if(find(arr.begin(),arr.end(),it)==arr.end()){
            arr.push_back(it);
            solve(result,arr,nums,size-1);
            arr.pop_back();
            }
        }
    }



    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>arr;
        int size=nums.size();
        solve(result,arr,nums,size);
        return result;
    }
};