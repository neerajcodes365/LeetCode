class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    int size = nums.size();
    sort(nums.begin(), nums.end());
    int l, r;
    for(int start=0;start<size-3;start++){
        if (start > 0 && nums[start] == nums[start - 1]) continue;
    for (int i = start+1; i < size - 2; i++) {
        if (i > start+1 && nums[i] == nums[i - 1]) continue;
        int sum = target-(nums[i]+nums[start]);
        l = i + 1;
        r = size - 1;
        while (l < r) {
            int sum2 = nums[l] + nums[r];
            if (sum2 == sum) {
                ans.push_back({nums[start],nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l + 1]) l++;
                while (l < r && nums[r] == nums[r - 1]) r--;
                l++;
                r--;
            }
            else if (sum2 > sum) {
                r--;
            }
            else {
                l++;
            }
        }
    }
    }
    return ans;
        
    }
};