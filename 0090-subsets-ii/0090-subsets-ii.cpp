class Solution {
private:
    void help(set<vector<int>>&result,vector<int>& nums,int index,vector<int>& arr){
        if(index > nums.size()) return;
        // vector<int> vt(arr.begin(), arr.end());
        // result.insert(vt);
        result.insert(arr);

        for(int j= index;j<nums.size();j++){
            if(j>index && nums[j]==nums[j-1]) continue;
            arr.push_back(nums[j]);
            help(result,nums,j+1,arr);
            arr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>result;
        vector<int>arr;
        sort(nums.begin(),nums.end());
        help(result,nums,0,arr);
        vector<vector<int>> resul(result.begin(),result.end());
        return resul;
    }
};