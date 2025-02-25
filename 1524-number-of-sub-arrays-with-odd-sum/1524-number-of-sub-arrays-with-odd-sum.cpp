/*
class Solution {
    tle
public:
    const int MOD = 1e9 + 7;

    void solve(vector<int>& arr, int index, int sum, int& count) {
        if (index >= arr.size()) return; 

        sum += arr[index]; 
        if (sum % 2 == 1) count = (count + 1) % MOD; 

        solve(arr, index + 1, sum, count); 
    }

    int numOfSubarrays(vector<int>& arr) {
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            solve(arr, i, 0, count); 
        }
        return count;
    }
};
*/
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int oddCount = 0, evenCount = 1; 
        int prefixSum = 0, result = 0;

        for (int num : arr) {
            prefixSum += num;
            
            if (prefixSum % 2 == 0) { 
                result = (result + oddCount) % MOD;  
                evenCount++;
            } else {  
                result = (result + evenCount) % MOD;  
                oddCount++;
            }
        }

        return result;
    }
};