/*
class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& arr, int sum, int start, unordered_map<int, int>& hash) {
        if (sum == target) {
            result.push_back(arr);
            return;
        }
        if (sum > target) return; 

        for (int i = start; i < candidates.size(); i++) { 
            if (hash[candidates[i]] > 0) {  
                arr.push_back(candidates[i]);
                hash[candidates[i]]--;  
                
                solve(candidates, target, result, arr, sum + candidates[i], i, hash);
                
                arr.pop_back();  
                hash[candidates[i]]++;  
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) { 
        sort(candidates.begin(), candidates.end()); 
        
        unordered_map<int, int> hash;
        for (int num : candidates) {
            hash[num]++;  
        }

        vector<vector<int>> result;
        vector<int> arr;
        
        solve(candidates, target, result, arr, 0, 0, hash); 
        set<vector<int>> uniqueSet(result.begin(), result.end());
        vector<vector<int>> uniqueresult(uniqueSet.begin(), uniqueSet.end());
        return uniqueresult;
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
            if(i>start && candidates[i]==candidates[i-1]) continue;//i>start il aan kali,recursion tree nokiya kathum.easy aan
            arr.push_back(candidates[i]);
            solve(candidates, target, result, arr, sum + candidates[i], i+1); 
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> arr;
        solve(candidates, target, result, arr, 0, 0); 
        return result;
    }
};