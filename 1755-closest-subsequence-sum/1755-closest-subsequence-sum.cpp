class Solution {
public:
    void helpsum(vector<int>& arr, int start, int end, vector<int>& result, int index, int sum) {
        result.push_back(sum);
        for (int i = index; i < end; i++) {
            sum += arr[i];
            helpsum(arr, start, end, result, i + 1, sum);
            sum -= arr[i];
        }
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int mid = n / 2;

        vector<int> fsthalf, sndhalf;
        helpsum(nums, 0, mid, fsthalf, 0, 0);        
        helpsum(nums, mid, n, sndhalf, mid, 0);      

        sort(sndhalf.begin(), sndhalf.end());

        int min = INT_MAX;
        for (int i = 0; i < fsthalf.size(); i++) {
            int num = fsthalf[i];
            int target = goal - num;
            auto it = lower_bound(sndhalf.begin(), sndhalf.end(), target);
 // suppose target is 5 and array is having 4,7,9 .we have to check the prv element also to ensure which is the smaLlest .
            if (it != sndhalf.end()) {
                int diff = abs(num + *it - goal);
                if (diff < min) min = diff;
            }
            if (it != sndhalf.begin()) {
                it--;
                int diff = abs(num + *it - goal);
                if (diff < min) min = diff;
            }
        }

        return min;
    }
};
