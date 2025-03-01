class Solution {
public:
    void solve(vector<vector<int>>&result,vector<int>&arr,int size,unordered_map<int,int>&hash){
        if(size==0){
            result.push_back(arr);
            return;
        }
        for(auto& itt:hash){
          //  if(find(arr.begin(),arr.end(),it)==arr.end()){
            int it=itt.first;
            if(hash[it]!=0){
            arr.push_back(it);
            hash[it]--;
            solve(result,arr,size-1,hash);
            arr.pop_back();
            hash[it]++;
            }
        }
    }

   vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>arr;
        int size=nums.size();
        unordered_map<int,int>hash;
        for(auto it:nums){
            hash[it]++;
        }
        solve(result,arr,size,hash);
        return result;
    }
};