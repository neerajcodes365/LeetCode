class Solution {
public:

    void solve(vector<vector<int>>&result,vector<int>&arr,vector<int>&nums,int index)
{
    if(arr.size()<=nums.size()){
        result.push_back(arr);
    //    return;
    }

    for(int i=index;i<nums.size();i++){
        arr.push_back(nums[i]);
        solve(result,arr,nums,i+1);
        arr.pop_back();
    }

}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>arr;
        // arr=[];
        solve(result,arr,nums,0);
        return result;
    }
};