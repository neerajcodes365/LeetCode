/*

class Solution {
public:
   // void solve(vector<int>& candidates, int target, vector<vector<int>>& result, int sum, vector<int>& arr) {
   void solve(vector<int>& candidates, int target, set<vector<int>>&result, int sum, vector<int>& arr) {
        if (sum == target) {
            vector<int>ar=arr;
            sort(ar.begin(),ar.end());
            // result.push_back(ar);
            result.insert(ar);
            return;
        }
        if (sum > target) return;
        for (int it : candidates) { 
            arr.push_back(it);
            solve(candidates, target, result, sum + it, arr);
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       // vector<vector<int>> result;
        set<vector<int>>result;
        vector<int> arr;
        solve(candidates, target, result, 0, arr);
        return vector<vector<int>>(result.begin(),result.end());
    }
};

*/
class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& arr, int sum, int start) {
        if (sum == target) {
            result.push_back(arr);
            return;
        }
        if (sum > target) return; 

        for (int i = start; i < candidates.size(); i++) { 
            arr.push_back(candidates[i]);
            solve(candidates, target, result, arr, sum + candidates[i], i); 
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> arr;
        solve(candidates, target, result, arr, 0, 0); 
        return result;
    }
};