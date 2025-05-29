class Solution {
    private:
    void help(vector<int>& candi,set<vector<int>>&res,int count,int target,vector<int>arr){
        if(count>target) return;
        if(count==target){
            sort(arr.begin(),arr.end());
            res.insert(arr);
        }
        for(int i=0;i<candi.size();i++){
            //if()
            arr.push_back(candi[i]);
            count+=candi[i];
            help(candi,res,count,target,arr);
            arr.pop_back();
            count-=candi[i];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candi, int target) {
        set<vector<int>>res;
        vector<int>arr;
        help(candi,res,0,target,arr);
        vector<vector<int>>result(res.begin(),res.end());
        return result;
    }
};