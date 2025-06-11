class Solution {
public:
    int rob(vector<int>& nums) {
       int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        if (size == 2) return max(nums[0], nums[1]);
        

        int case1 = 0, case2 = 0;
        
        
            vector<int> arr(size - 1);
            arr[0] = nums[0];
            int prev = 0;
            for (int i = 1; i < size - 1; i++) {
                arr[i] = max(arr[i-1], nums[i] + prev);
                prev = arr[i-1];
            }
            case1 = arr[size - 2];
        
        
        
        
            vector<int> ar(size - 1);
            ar[0] = nums[1];
            int prev2 = 0;
            for (int i = 1; i < size - 1; i++) {
                ar[i] = max(ar[i-1], nums[i + 1] + prev2);
                prev2 = ar[i-1];
            }
            case2 = ar[size - 2];
        
        
        return max(case1, case2);
    }
};