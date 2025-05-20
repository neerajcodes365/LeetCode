// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>>ans;
//         int size = nums.size();
//         for(int i=0;i<size;i++){
//             unordered_set<int>hash;
//             for(int j=i+1;j<size;j++){
//                 int compli=-(nums[i]+nums[j]);
//                 if(hash.find(compli)!=hash.end()){
//                     vector<int>help={nums[i],nums[j],compli};
//                     sort(help.begin(),help.end());
//                     ans.insert(help);
//                 }
//                 hash.insert(nums[j]);
//             }
//         }
//         return vector<vector<int>>(ans.begin(), ans.end());
//     }
// };
class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    int size = nums.size();
    sort(nums.begin(), nums.end());
    int l, r;
    for (int i = 0; i < size - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int sum = -nums[i];
        l = i + 1;
        r = size - 1;
        while (l < r) {
            int sum2 = nums[l] + nums[r];
            if (sum2 == sum) {
                ans.push_back({nums[i], nums[l], nums[r]});
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
    return ans;
}
};

    